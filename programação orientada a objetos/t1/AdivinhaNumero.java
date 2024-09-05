package t1;

import java.util.Scanner;
import java.util.Random;
import java.util.InputMismatchException;

public class AdivinhaNumero {
    private static final int MAX_NUMBER = 1000;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random random = new Random();

        String player1Name = askForPlayerName(scanner, "Jogador 1: ");
        String player2Name = askForPlayerName(scanner, "Jogador 2: ");

        String startingPlayer = getRandomPlayer(random, player1Name, player2Name);
        System.out.println("Jogador sorteado para comecar: " + startingPlayer);

        int secretNumber = generateSecretNumber(random);
        playGame(scanner, startingPlayer, player1Name, player2Name, secretNumber);
    }

    private static String askForPlayerName(Scanner scanner, String prompt) {
        System.out.print(prompt);
        return scanner.nextLine();
    }

    private static String getRandomPlayer(Random random, String player1Name, String player2Name) {
        return random.nextBoolean() ? player1Name : player2Name;
    }

    private static int generateSecretNumber(Random random) {
        return random.nextInt(MAX_NUMBER) + 1;
    }

    private static void playGame(Scanner scanner, String startingPlayer, String player1Name, String player2Name, int secretNumber) {
        boolean currentPlayer = startingPlayer.equals(player1Name);
        while (true) {
            String currentPlayerName = currentPlayer ? player1Name : player2Name;
            System.out.print("Palpite " + currentPlayerName + ": ");
            try {
                int guess = scanner.nextInt();
                scanner.nextLine(); // Consumir a quebra de linha

                if (guess == secretNumber) {
                    System.out.println(currentPlayerName + " ganhou!");
                    break;
                }

                if (guess < secretNumber) {
                    System.out.println("Computador: numero eh maior");
                }

                if (guess > secretNumber) {
                    System.out.println("Computador: numero eh menor");
                }
            } catch (InputMismatchException e) {
                System.out.println("Erro: você deve digitar um número!");
                scanner.nextLine(); // Consumir a entrada inválida
            }

            currentPlayer = !currentPlayer;
        }
    }
}