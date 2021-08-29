/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package clock;

import java.util.Scanner;


/**
 *
 * @author emeps
 */
public class Clock {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        Hours hora = new Hours();

        new Thread(new Runnable() {
            public void run() {
                try {
                    hora.clockHours();
                } catch (Exception e) {
                    System.out.println("Não foi possivél executar o relógio!");
                    System.exit(0);
                }
            }
        }).start();

        String opc = "";
        int clockMain[] = new int[3];

        Scanner keyboard = new Scanner(System.in);
        while (opc != "E" || opc != "e") {
            System.out.print("\033[H\033[2J");
            System.out.flush();
            System.out.println("MENU");
            System.out.println("1 - Programar Hora, Minutos e Segundos");
            System.out.println("2 - Programar Hora e Minutos");
            System.out.println("3 - Programar Despertador");
            System.out.println("4 - Mostrar a Hora Corrente");
            System.out.println("E - Para Sair do Programa");
            opc = String.valueOf(keyboard.nextLine());
            switch (opc) {
                case "1":
                    System.out.println("Programando Horario");
                    System.out.println(
                            "Insira o valor da hora, em seguida do valor do minutos e opcionalmente valor dos segundos.");
                    for (int i = 0; i < 3; i++) {
                        clockMain[i] = Integer.parseInt(keyboard.nextLine());
                    }
                    hora.setHours(clockMain[0], clockMain[1], clockMain[2]);
                    System.out.println(
                            "Horario Programado: " + clockMain[0] + " : " + clockMain[1] + " : " + clockMain[2]);
                    System.out.println("Pressione qualquer tecla para voltar ao menu principal");
                    keyboard.nextLine();
                    break;

                case "2":
                    System.out.println("Programando Horario");
                    System.out.println("Insira o valor da hora, em seguida do valor do minutos.");
                    for (int i = 0; i < 2; i++) {
                        clockMain[i] = Integer.parseInt(keyboard.nextLine());
                    }
                    hora.setHours(clockMain[0], clockMain[1]);
                    System.out.println("Horario Programado: " + clockMain[0] + " : " + clockMain[1]);
                    System.out.println("Pressione qualquer tecla para voltar ao menu principal");
                    keyboard.nextLine();
                    break;

                case "3":
                    System.out.println("Estou Programando Despertador");
                    System.out.println("Insira o valor da hora, em seguida do valor do minutos.");
                    for (int i = 0; i < 2; i++) {
                        clockMain[i] = Integer.parseInt(keyboard.nextLine());
                    }
                    hora.setClockAlarm(clockMain[0], clockMain[1]);
                    System.out.println("Pressione qualquer tecla para voltar ao menu principal");
                    keyboard.nextLine();
                    break;
                    
                case "4":
                    System.out.println("Estou Mostando");
                    hora.displayHours();
                    System.out.println("Pressione qualquer tecla para voltar ao menu principal");
                    keyboard.nextLine();
                    break;

                case "E":
                    System.out.println("Estou Saindo");
                    System.out.println("Pressione qualquer tecla para sair");
                    keyboard.nextLine();
                    System.exit(0);
                    break;

                case "e":
                    System.out.println("Estou Saindo");
                    System.out.println("Pressione qualquer tecla para sair");
                    keyboard.nextLine();
                    System.exit(0);
                    break;

                default:
                    System.out.println("Opção invalida!");
                    System.out.println("Pressione qualquer tecla para voltar ao menu principal");
                    keyboard.nextLine();
                    break;
            }
        }
    }
}
