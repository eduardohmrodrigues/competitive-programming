package com.competitive.uva.game.card;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] princess = new int[3];
        int[] prince = new int[2];
        int lowestCard;
        Set<Integer> usedCards = new HashSet<Integer>();
        Set<Integer> princessUsedCards = new HashSet<Integer>();
        princess[0] = scanner.nextInt();
        while(princess[0] != 0) {
            usedCards.clear();
            princessUsedCards.clear();
            usedCards.add(princess[0]);
            for(int i=1; i<3; ++i) {
                princess[i] = scanner.nextInt();
                usedCards.add(princess[i]);
            }
            for(int i=0; i<2; ++i) {
                prince[i] = scanner.nextInt();
                usedCards.add(prince[i]);
            }
            Arrays.sort(princess);
            Arrays.sort(prince);

            for(int i=0; i<3; ++i){
                if(prince[1] < princess[i]) {
                    princessUsedCards.add(princess[i]);
                    break;
                }
            }

            for(int i=0; i<3; ++i){
                if(prince[0] < princess[i] && !princessUsedCards.contains(princess[i])) {
                    princessUsedCards.add(princess[i]);
                    break;
                }
            }

            lowestCard = -1;
            if(princessUsedCards.size() == 1) {
                for(int i=2; i>0 && lowestCard == -1; --i){
                    if(princessUsedCards.contains(princess[i])) continue;
                    else{
                        for(int j=princess[i]+1; j<=52 && lowestCard == -1; ++j){
                            if(!usedCards.contains(j)) lowestCard = j;
                        }

                        if(lowestCard == -1) break;
                    }
                }
            }else if(princessUsedCards.size() == 0){
                for(int i=1; i<=52 && lowestCard == -1; ++i){
                    if(!usedCards.contains(i)) lowestCard = i;
                }
            }

            System.out.println(lowestCard);
            princess[0] = scanner.nextInt();
        }
    }
}
