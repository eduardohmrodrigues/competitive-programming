package com.competitive.uva.medium;

import java.util.Scanner;


class Vec3 {
    public int x;
    public int y;
    public int z;

    public Vec3(int x, int y, int z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public void rotateY(int rot) {
        if(x != 0) {
            setY(x*rot);
        }else if(y != 0){
            setX(-y*rot);
        }//do not affect z
    }

    public void rotateZ(int rot) {
        if(x != 0) {
            setZ(x*rot);
        }else if(z != 0){
            setX(-z*rot);
        }//do not affect y
    }

    public void rotate(int rotY, int rotZ) {
        if(rotY == 1 || rotY == -1) {
            rotateY(rotY);
        }else if(rotZ == 1 || rotZ == -1){
            rotateZ(rotZ);
        }
    }

    public void setX(int x){
        this.x = x; this.y = 0; this.z = 0;
    }

    public void setY(int y){
        this.x = 0; this.y = y; this.z = 0;
    }

    public void setZ(int z){
        this.x = 0; this.y = 0; this.z = z;
    }

    public void print(){
        String val = "+x";
        if(x == -1) val = "-x";
        else if (y == 1) val = "+y";
        else if (y == -1) val = "-y";
        else if (z == 1) val = "+z";
        else if (z == -1) val = "-z";

        System.out.println(val);
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int l = scanner.nextInt();
        String operation;
        Vec3 vec3 = new Vec3(1, 0, 0);

        while(l != 0) {
            vec3.setX(1);
            for(int i=1; i<l; ++i){
                operation = scanner.next();
                switch (operation) {
                    case "+y":
                        vec3.rotate(1, 0);
                        break;
                    case "-y":
                        vec3.rotate(-1, 0);
                        break;
                    case "+z":
                        vec3.rotate(0, 1);
                        break;
                    case "-z":
                        vec3.rotate(0, -1);
                        break;
                    default:
                        break;
                }
            }

            vec3.print();
            l = scanner.nextInt();
        }
    }

}
