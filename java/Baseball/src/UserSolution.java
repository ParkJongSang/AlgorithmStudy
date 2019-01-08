/*

4자리 숫자를 맞출수 있는 인공지능을 만드는 문제

1.임의의 숫자를 컴퓨터에게 물어본다.

2.1B 1S라고 결과를 알려줬다면 1234~9876에서 물어본 숫자와 1B 1S가 나오는 숫자를 제외한 나머지 숫자를 리스트에서 삭제한다.

3.1개가 남을 때까지 1~2를 반복한다.

 */

class UserSolution {
    public final static int N = 4;
    private int guess_c[] = new int[10];
    private List mList = new List();

    private boolean isValid(int guess[]) {
        for (int count = 0; count < 10; ++count) guess_c[count] = 0;
        for (int idx = 0; idx < N; ++idx) {
            if (guess[idx] < 0 || guess[idx] >= 10 || guess_c[guess[idx]] > 0) return false;
            guess_c[guess[idx]]++;
        }
        return true;
    }

    public void doUserImplementation(int guess[]) {
        // Implement a user's implementation function
        //
        // The array of guess[] is a return array that
        // is your guess for what digits[] would be.
        int[] arr = new int[4];

        makeList(mList);

        while(mList.size() > 1){
            arr = mList.getFirst().value;
            Solution.Result temp = Solution.query(arr);
            compare(arr, mList, temp.ball, temp.strike);
        }

        for(int idx = 0; idx < guess.length; idx++){
            guess[idx] = mList.getFirst().value[idx];
            //System.out.println(guess[idx]);
        }
        return;
    }

    public void makeList(List list){
        for(int a = 0; a < 10; a++){
            for(int b = 0; b < 10; b++){
                for(int c = 0; c < 10; c++){
                    for(int d = 0; d < 10; d++){
                        if(a != b && a != c && a != d
                                && b != c && b != d
                                && c != d){
                            int[] toAdd = {a, b, c, d};
                            list.addLast(toAdd);
                        }
                    }
                }
            }
        }
    }

    public void compare(int arr[], List list, int ball, int strike) {
        Solution.Result result = new Solution.Result();

        int count = 0;
        //int de_count = 0;
        List.Node temp = list.getFirst();

        isValid(temp.value);

        while(temp != null){

            result.strike = 0;
            result.ball = 0;

            for (int idx = 0; idx < N; idx++) {
                if (arr[idx] == temp.value[idx]) {
                    result.strike++;
                } else if (guess_c[temp.value[idx]] > 0) {
                    result.ball++;
                }
            }

            if(ball == result.ball && strike == result.strike){
                count++;
            }else{
                //System.out.println(de_count++);
                list.remove(count);
            }


            temp = temp.next;
        }
    }


}

class List{
    class Node{
        Node next;
        int[] value = new int[4];
    }

    private Node head;
    private Node tail;
    private int size = 0;

    public void addFirst(int[] a){
        Node new_node = new Node();
        new_node.value = a;

        new_node.next = head;
        head = new_node;

        size++;

        if(head.next == null){
            tail = head;
        }
    }

    public void addLast(int[] a){
        Node new_node = new Node();
        new_node.value = a;

        if(size == 0){
            addFirst(a);
        }else{
            tail.next = new_node;
            tail = new_node;
            size++;
        }
    }

    public void add(int idx, Node node){
        if(idx == 0){
            addFirst(node.value);
        }else{
            Node temp1 = nodeIndex(idx-1);
            Node temp2 = temp1.next;

            temp1.next = node;
            node.next = temp2;

            size++;

            if(node.next == null){
                tail = node;
            }
        }
    }

    public Node removeFirst(){
        Node toRemove = new Node();
        toRemove = head;
        head = head.next;
        size--;
        return toRemove;
    }

    public Node remove(int idx){
        if(idx == 0){
            return removeFirst();
        }else{
            Node temp1 = nodeIndex(idx-1);
            Node toRemove = temp1.next;

            temp1.next = temp1.next.next;

            if(toRemove == tail){
                tail = temp1;
            }

            size--;

            return toRemove;
        }
    }

    public int size(){
        return size;
    }

    public Node getFirst(){
        return head;
    }

    private Node nodeIndex(int idx){
        Node x = head;
        for(int i = 0; i < idx; i++){
            x = x.next;
        }
        return x;
    }
}