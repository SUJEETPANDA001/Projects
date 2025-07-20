import java.util.Arrays;

public class Question {
    private int id;
    private String Question;
    private String[] options;
    private String answer;
    public Question(int id, String question, String[] options, String answer) {
        this.id = id;
        Question = question;
        this.options = options;
        this.answer = answer;
    }
    public int getId() {
        return id;
    }
    public void setId(int id) {
        this.id = id;
    }
    public String getQuestion() {
        return Question;
    }
    public void setQuestion(String question) {
        Question = question;
    }
    @Override
    public String toString() {
        return "Question [id=" + id + ", Question=" + Question + ", options=" + Arrays.toString(options) + ", answer="
                + answer + "]";
    }
    public String[] getOptions() {
        return options;
    }
    public void setOptions(String[] options) {
        this.options = options;
    }
    public String getAnswer() {
        return answer;
    }
    public void setAnswer(String answer) {
        this.answer = answer;
    }
    
    
}
