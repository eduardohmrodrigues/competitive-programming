import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int kCourses, mCategories, cCoursesPerCategories, rMinimumPerCategory, tookAmount;
        String currCourse;
        Set<String> selectedCourses = new HashSet<String>(105);
        boolean meetsRequirements;

        kCourses = scanner.nextInt();
        while(kCourses != 0) {
            meetsRequirements = true;
            selectedCourses.clear();
            mCategories = scanner.nextInt();

            for(int i=0; i<kCourses; ++i) {
                currCourse = scanner.next();
                selectedCourses.add(currCourse);
            }

            for(int i=0; i<mCategories; ++i){
                tookAmount = 0;
                cCoursesPerCategories = scanner.nextInt();
                rMinimumPerCategory = scanner.nextInt();

                for(int j=0; j<cCoursesPerCategories; ++j){
                    currCourse = scanner.next();
                    if(selectedCourses.contains(currCourse)) ++tookAmount;
                }

                meetsRequirements &= rMinimumPerCategory <= tookAmount;
            }

            if(meetsRequirements) System.out.println("yes");
            else System.out.println("no");
            kCourses = scanner.nextInt();
        }
    }
}
