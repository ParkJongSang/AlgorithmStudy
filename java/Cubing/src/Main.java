import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static int T;
    static int rotateNum;
    static String[] rotates;
    static final int FRONT = 0;
    static final int BACK = 1;
    static final int UP = 2;
    static final int DOWN = 3;
    static final int RIGHT = 4;
    static final int LEFT = 5;

    public static void main(String[] args) {
        T = sc.nextInt();
        for(int testcase = 1; testcase <= T; testcase++){
            rotateNum = sc.nextInt();
            rotates = new String[rotateNum];
            for(int i = 0; i < rotateNum; i++){
                rotates[i] = sc.next();
            }
        }
    }

    public void createCube(){
        Cube[] cubes = new Cube[6];
        //0 앞, 1 뒤, 2 위, 3 아래, 4 오른쪽, 5 왼쪽

        for(int i = 0; i < 6; i++){
            cubes[i] = new Cube();
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cubes[FRONT].color[i][j] = 'r';
                cubes[BACK].color[i][j] = 'o';
                cubes[UP].color[i][j] = 'w';
                cubes[DOWN].color[i][j] = 'y';
                cubes[RIGHT].color[i][j] = 'b';
                cubes[DOWN].color[i][j] = 'g';
            }
        }
        //앞
        cubes[FRONT].up = cubes[UP]; cubes[FRONT].down = cubes[DOWN]; cubes[FRONT].left = cubes[LEFT]; cubes[FRONT].right = cubes[RIGHT];
        //뒤
        cubes[BACK].up = cubes[UP]; cubes[BACK].down = cubes[DOWN]; cubes[BACK].left = cubes[RIGHT]; cubes[BACK].right = cubes[LEFT];
        //위
        cubes[UP].up = cubes[BACK]; cubes[UP].down = cubes[FRONT]; cubes[UP].left = cubes[LEFT]; cubes[UP].right = cubes[RIGHT];
        //아래
        cubes[DOWN].up = cubes[FRONT]; cubes[DOWN].down = cubes[BACK]; cubes[DOWN].left = cubes[LEFT]; cubes[DOWN].right = cubes[RIGHT];
        //오른쪽
        cubes[RIGHT].up = cubes[UP]; cubes[RIGHT].down = cubes[DOWN]; cubes[RIGHT].left = cubes[FRONT]; cubes[RIGHT].right = cubes[BACK];
        //왼쪽
        cubes[LEFT].up = cubes[UP]; cubes[LEFT].down = cubes[DOWN]; cubes[LEFT].left = cubes[BACK]; cubes[LEFT].right = cubes[FRONT];
    }

    public void rotateColor(Cube[] cubes, String rotate){
        char phase = rotate.charAt(0);
        char clock = rotate.charAt(1);

        switch(phase){
            case 'F':
                if(clock == '+'){
                    char[] temp = new char[3];

                    for(int i = 0; i < 3; i++){
                        cubes.
                    }
                    for(int i = 0; i < 3; i++){
                        cubes[].right.color[0][i] = cubes[FRONT].up.color[2][i];
                    }
                }else if(clock == '-'){

                }
                break;
            case 'B':
                if(clock == '+'){

                }else if(clock == '-'){

                }
                break;
            case 'U':
                if(clock == '+'){

                }else if(clock == '-'){

                }
                break;
            case 'D':
                if(clock == '+'){

                }else if(clock == '-'){

                }
                break;
            case 'R':
                if(clock == '+'){

                }else if(clock == '-'){

                }
                break;
            case 'L':
                if(clock == '+'){

                }else if(clock == '-'){

                }
                break;

        }
    }
}

class Cube{
    char[][] color = new char[3][3];
    Cube up, down, left, right;
}
