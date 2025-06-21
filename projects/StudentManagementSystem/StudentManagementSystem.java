import java.io.*;
import java.util.*;

public class StudentManagementSystem {
    // Student class (inner class)
    private static class Student implements Serializable {
        private String id;
        private String name;
        private int age;
        private String grade;

        public Student(String id, String name, int age, String grade) {
            this.id = id;
            this.name = name;
            this.age = age;
            this.grade = grade;
        }

        @Override
        public String toString() {
            return String.format("ID: %s, Name: %s, Age: %d, Grade: %s", id, name, age, grade);
        }

        public String getId() { return id; }
        public String getName() { return name; }
        public int getAge() { return age; }
        public String getGrade() { return grade; }
        
        public void setName(String name) { this.name = name; }
        public void setAge(int age) { this.age = age; }
        public void setGrade(String grade) { this.grade = grade; }
    }

    private static final String DATA_FILE = "students.dat";
    private static List<Student> students = new ArrayList<>();
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        loadStudentsFromFile();
        
        while (true) {
            System.out.println("\nStudent Management System");
            System.out.println("1. Add New Student");
            System.out.println("2. View All Students");
            System.out.println("3. Search Student by ID");
            System.out.println("4. Update Student Details");
            System.out.println("5. Delete Student Record");
            System.out.println("6. Exit");
            System.out.print("Enter your choice: ");
            
            try {
                int choice = Integer.parseInt(scanner.nextLine());
                
                switch (choice) {
                    case 1:
                        addStudent();
                        break;
                    case 2:
                        viewAllStudents();
                        break;
                    case 3:
                        searchStudent();
                        break;
                    case 4:
                        updateStudent();
                        break;
                    case 5:
                        deleteStudent();
                        break;
                    case 6:
                        saveStudentsToFile();
                        System.out.println("Exiting system. Goodbye!");
                        System.exit(0);
                    default:
                        System.out.println("Invalid choice. Please try again.");
                }
            } catch (NumberFormatException e) {
                System.out.println("Please enter a valid number.");
            }
        }
    }

    private static void addStudent() {
        System.out.println("\nAdd New Student");
        System.out.print("Enter Student ID: ");
        String id = scanner.nextLine();
        
        // Check if student already exists
        if (findStudentById(id) != null) {
            System.out.println("Student with this ID already exists!");
            return;
        }
        
        System.out.print("Enter Student Name: ");
        String name = scanner.nextLine();
        
        System.out.print("Enter Student Age: ");
        int age = Integer.parseInt(scanner.nextLine());
        
        System.out.print("Enter Student Grade: ");
        String grade = scanner.nextLine();
        
        students.add(new Student(id, name, age, grade));
        System.out.println("Student added successfully!");
    }

    private static void viewAllStudents() {
        System.out.println("\nAll Students");
        if (students.isEmpty()) {
            System.out.println("No students found.");
            return;
        }
        
        for (Student student : students) {
            System.out.println(student);
        }
    }

    private static void searchStudent() {
        System.out.print("\nEnter Student ID to search: ");
        String id = scanner.nextLine();
        Student student = findStudentById(id);
        
        if (student != null) {
            System.out.println("Student found:");
            System.out.println(student);
        } else {
            System.out.println("Student not found with ID: " + id);
        }
    }

    private static void updateStudent() {
        System.out.print("\nEnter Student ID to update: ");
        String id = scanner.nextLine();
        Student student = findStudentById(id);
        
        if (student == null) {
            System.out.println("Student not found with ID: " + id);
            return;
        }
        
        System.out.println("Current details:");
        System.out.println(student);
        
        System.out.print("Enter new name (leave blank to keep current): ");
        String name = scanner.nextLine();
        if (!name.isEmpty()) student.setName(name);
        
        System.out.print("Enter new age (0 to keep current): ");
        int age = Integer.parseInt(scanner.nextLine());
        if (age != 0) student.setAge(age);
        
        System.out.print("Enter new grade (leave blank to keep current): ");
        String grade = scanner.nextLine();
        if (!grade.isEmpty()) student.setGrade(grade);
        
        System.out.println("Student details updated successfully!");
    }

    private static void deleteStudent() {
        System.out.print("\nEnter Student ID to delete: ");
        String id = scanner.nextLine();
        Student student = findStudentById(id);
        
        if (student == null) {
            System.out.println("Student not found with ID: " + id);
            return;
        }
        
        students.remove(student);
        System.out.println("Student deleted successfully!");
    }

    private static Student findStudentById(String id) {
        for (Student student : students) {
            if (student.getId().equals(id)) {
                return student;
            }
        }
        return null;
    }

    @SuppressWarnings("unchecked")
    private static void loadStudentsFromFile() {
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(DATA_FILE))) {
            students = (List<Student>) ois.readObject();
            System.out.println("Student data loaded successfully.");
        } catch (FileNotFoundException e) {
            System.out.println("No existing data file found. Starting with empty list.");
        } catch (IOException | ClassNotFoundException e) {
            System.out.println("Error loading student data: " + e.getMessage());
        }
    }

    private static void saveStudentsToFile() {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(DATA_FILE))) {
            oos.writeObject(students);
            System.out.println("Student data saved successfully.");
        } catch (IOException e) {
            System.out.println("Error saving student data: " + e.getMessage());
        }
    }
}