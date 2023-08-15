// https://www.hackerrank.com/challenges/time-conversion/problem
public static String timeConversion(String s) {
    String hour = s.substring(0, 2);

    if(s.charAt(s.length()-2) == 'A' && hour.equals("12")) {
        System.out.println("If 1");
        return "00" + s.substring(2, s.length()-2);
    } else if(s.charAt(s.length()-2) == 'P' && !hour.equals("12")) {
        System.out.println("If 2");
        int hourInt = Integer.parseInt(hour)+12;
        return hourInt + s.substring(2, s.length()-2);
    }

    System.out.println("Else");
    return s.substring(0, s.length()-2);
}
