package t1;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Piramide {
    private static final int MIN_LINES = 1;
    private static final int MAX_LINES = 9;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numberOfLines = askForNumberOfLines(scanner);

        printPyramid(numberOfLines);

        scanner.close();
    }

    private static int askForNumberOfLines(Scanner scanner) {
        while (true) {
            try {
                System.out.print("Digite o número de linhas (entre " + MIN_LINES + " e " + MAX_LINES + "): ");
                int numberOfLines = scanner.nextInt();

                if (numberOfLines < MIN_LINES || numberOfLines > MAX_LINES) {
                    System.out.println("Número de linhas inválido. Por favor, digite um número entre " + MIN_LINES + " e " + MAX_LINES + ".");
                } else {
                    return numberOfLines;
                }
            } catch (InputMismatchException e) {
                System.out.println("Valor inválido. Por favor, digite um número inteiro.");
                scanner.next(); // Limpar o buffer de entrada
            }
        }
    }

    private static void printPyramid(int numberOfLines) {
        for (int i = 1; i <= numberOfLines; i++) {
            printSpaces(numberOfLines - i);
            printIncreasingNumbers(i);
            printDecreasingNumbers(i - 1);
            System.out.println();
        }
    }

    private static void printSpaces(int numberOfSpaces) {
        for (int i = 0; i < numberOfSpaces; i++) {
            System.out.print(" ");
        }
    }

    private static void printIncreasingNumbers(int numberOfNumbers) {
        for (int i = 1; i <= numberOfNumbers; i++) {
            System.out.print(i);
        }
    }

    private static void printDecreasingNumbers(int numberOfNumbers) {
        for (int i = numberOfNumbers; i >= 1; i--) {
            System.out.print(i);
        }
    }
}