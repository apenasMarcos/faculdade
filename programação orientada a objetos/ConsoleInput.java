import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class ConsoleInput {

   public static void main(String[] args) {

       String nome, longestName = "";
       int maxLength = 0;
       try {
           Scanner in = new Scanner(new File("util/nomes.txt"));

           while (in.hasNext()) {
               nome = in.nextLine();
               System.out.println(nome);

               if (nome.length() > maxLength) {
                   maxLength = nome.length();
                   longestName = nome;
               }
           }
           in.close();

           System.out.println("Nome com a maior quantidade de caracteres: " + longestName);
       } catch (FileNotFoundException e) {
           System.out.println("Arquivo não encontrado!");
       }
   }
}