public static List<Integer> getMax(List<String> operations) {
    TreeMap<Integer, Integer> elementToCount = new TreeMap<Integer, Integer>();
    Deque<Integer> stack = new ArrayDeque<>();
    List<Integer> myList = new ArrayList<>();
    
    for(int i=0; i<operations.size(); ++i) {
        String curr = operations.get(i);
        int operation = curr.charAt(0) - '0';
        if(operation == 1) {
            int currValue = Integer.parseInt(curr.substring(2));
            stack.add(currValue);
            if(!elementToCount.containsKey(currValue)) elementToCount.put(currValue, 0);
            elementToCount.put(currValue, elementToCount.get(currValue)+1);
        } else if (operation == 2) {
            int currValue = stack.removeLast();
            int currOccurencesOfValue = elementToCount.get(currValue);
            if(currOccurencesOfValue == 1) {
                elementToCount.remove(currValue);
            } else {
                elementToCount.put(currValue, elementToCount.get(currValue)-1);
            }
        } else {
            Map.Entry<Integer, Integer> entry = elementToCount.lastEntry();
            myList.add(entry.getKey());
        }
    }
    
    return myList;
}
