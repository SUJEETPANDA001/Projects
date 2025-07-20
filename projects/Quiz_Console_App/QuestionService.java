import java.util.Scanner;

public class QuestionService {
    Question[] questions=new Question[5];
    String ans[]=new String[5];
    public QuestionService(){
        questions[0] = new Question(1, "Size of int :", new String[]{"2", "6", "4", "8"}, "4");
        questions[1] = new Question(2, "Size of double :", new String[]{"2", "6", "4", "8"}, "8");
        questions[2] = new Question(3, "Size of char :", new String[]{"2", "6", "4", "8"}, "2");
        questions[3] = new Question(4, "Size of long :", new String[]{"2", "6", "4", "8"}, "8");
        questions[4] = new Question(5, "Size of boolean :", new String[]{"1", "2", "4", "8"}, "1");
    
    }

    public void playQuiz(){
        int j=0;
        for(Question q:questions){
            System.out.println("Question No :"+q.getId());
            System.out.println(q.getQuestion()); 

            String[] opts = q.getOptions();
            for (int i = 0; i < opts.length; i++) {
                System.out.println((i + 1) + ". " + opts[i]);
            }
            Scanner sc=new Scanner(System.in);
            ans[j++] = sc.nextLine();
        }
        for(String s:ans){
            System.out.println(s);
        }
    }

    public void printScore(){
        int score=0;
        for(int i=0;i<questions.length;i++){
            if(ans[i].equals(questions[i].getAnswer())){
                score++;
            }
        }
        System.out.println("Your score is "+score);
    }
}
