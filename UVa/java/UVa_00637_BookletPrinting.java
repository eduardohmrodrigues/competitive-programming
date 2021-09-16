import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Sheet{
    int p1, p2, p3, p4;

    public Sheet(int p1, int p2, int p3, int p4) {
        this.p1 = p1; this.p2 = p2; this.p3 = p3; this.p4 = p4;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int pages = scanner.nextInt(), sheets, sheet, page, direction;
        List<Sheet> booklet = new ArrayList<Sheet>();
        Sheet curr;
        while(pages != 0) {
            booklet.clear();
            sheets = (pages/4) + (pages%4 > 0 ? 1 : 0);
            page = 1;
            sheet = 1;
            direction = 1;

            while(page <= pages){
                if(booklet.size() < sheets) booklet.add(new Sheet(-1, -1, -1 , -1));

                if(direction == 1) {
                    booklet.get(sheet-1).p1 = page;
                    if(page+1 <= pages) booklet.get(sheet-1).p2 = page+1;
                }else{
                    booklet.get(sheet-1).p3 = page;
                    if(page+1 <= pages) booklet.get(sheet-1).p4 = page+1;
                }

                sheet += direction;
                if(sheet > sheets){
                    direction = -1;
                    --sheet;
                }

                page+=2;
            }

            System.out.println("Printing order for " + pages + " pages:");
            for(int i=0; i<booklet.size(); ++i){
                printSheet(booklet.get(i), i);
            }
            pages = scanner.nextInt();
        }
    }

    public static void printSheet(Sheet curr, int page){
        if(curr.p1 != -1 || curr.p4 != -1) {
            System.out.print("Sheet " + (page+1) + ", front: ");
            if(curr.p4 != -1) System.out.print(curr.p4 + ", ");
            else System.out.print("Blank, ");

            if(curr.p1 != -1) System.out.print(curr.p1);
            else System.out.print("Blank");

            System.out.println();
        }

        if(curr.p2 != -1 || curr.p3 != -1) {
            System.out.print("Sheet " + (page+1) + ", back : ");
            if(curr.p2 != -1) System.out.print(curr.p2 + ", ");
            else System.out.print("Blank, ");

            if(curr.p3 != -1) System.out.print(curr.p3);
            else System.out.print("Blank");

            System.out.println();
        }
    }
}
