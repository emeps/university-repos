/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lista.pkg1;

import javax.swing.JOptionPane;

/**
 *
 * @author emeps
 */
public class Lista1 {

    /**
     * @param args the command line arguments
     */

    public static void fibonacci(int num) {
        int primeiroTermo = 0;
        int segundoTermo = 1;
        String seqFibonacci = "0";
        for (int i = 1; i < num; i++) {
            seqFibonacci = seqFibonacci + " " + String.valueOf(segundoTermo);
            segundoTermo += primeiroTermo;
            primeiroTermo = segundoTermo - primeiroTermo;
        }
        System.out.println("Série Fibonacci:" + seqFibonacci);
        JOptionPane.showMessageDialog(null, seqFibonacci, "Série Fibonacci " + num + " termo.",
                JOptionPane.INFORMATION_MESSAGE);
    }

    public static void main(String[] args) {
        // TODO code application logic here
        int valor;
        valor = Integer
                .parseInt(JOptionPane.showInputDialog("Insira o número de termos desejado para Sequência Fibonacci"));
        fibonacci(valor);
    }

}
