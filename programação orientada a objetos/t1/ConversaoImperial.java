package t1;

import java.util.InputMismatchException;
import java.util.Scanner;

public class ConversaoImperial {
    // Constantes de conversão
    private static final double CENTIMETERS_TO_MILLIMETERS = 10.0;
    private static final double MILLIMETERS_TO_INCHES = 1 / 25.3995;
    private static final double INCHES_TO_FEET = 1 / 12.0;
    private static final double FEET_TO_YARDS = 1 / 3.0;
    private static final double YARDS_TO_MILES = 1 / 1760.0;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            try {
                System.out.print("Digite o valor em centímetros (ou -1 para sair): ");
                double centimeters = scanner.nextDouble();

                if (centimeters == -1) {
                    break;
                }

                if (centimeters < 0) {
                    System.out.println("Valor inválido. Por favor, digite um valor não negativo.");
                    continue;
                }

                double millimeters = convertCentimetersToMillimeters(centimeters);
                double inches = convertMillimetersToInches(millimeters);
                double feet = convertInchesToFeet(inches);
                double yards = convertFeetToYards(feet);
                double miles = convertYardsToMiles(yards);

                printConversionResults(inches, feet, yards, miles);
            } catch (InputMismatchException e) {
                System.out.println("Valor inválido. Por favor, digite um número real.");
                scanner.next(); // Limpar o buffer de entrada
            }
        }

        // Fechar o scanner
        scanner.close();
    }

    private static double convertCentimetersToMillimeters(double centimeters) {
        return centimeters * CENTIMETERS_TO_MILLIMETERS;
    }

    private static double convertMillimetersToInches(double millimeters) {
        return millimeters * MILLIMETERS_TO_INCHES;
    }

    private static double convertInchesToFeet(double inches) {
        return inches * INCHES_TO_FEET;
    }

    private static double convertFeetToYards(double feet) {
        return feet * FEET_TO_YARDS;
    }

    private static double convertYardsToMiles(double yards) {
        return yards * YARDS_TO_MILES;
    }

    private static void printConversionResults(double inches, double feet, double yards, double miles) {
        System.out.printf("O valor em polegadas é: %.2f in%n", inches);
        System.out.printf("O valor em pés é: %.2f ft%n", feet);
        System.out.printf("O valor em jardas é: %.2f yd%n", yards);
        System.out.printf("O valor em milhas é: %.6f mi%n", miles);
    }
}