/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lista.pkg03;

import javax.swing.JOptionPane;

/**
 *
 * @author emeps
 */
public class Lista03 {

    /**
     * @param args the command line arguments
     */

    public static void main(String[] args) {    
        int []vetorGerado = geradorDeVetor(20);
        String vetorDePrimos = " ";
        for (int i = 1; i < vetorGerado.length; i++) {
            if( verificadorPrimo(vetorGerado[i] ))
                vetorDePrimos += " "+String.valueOf(vetorGerado[i]); 
        } 
        JOptionPane.showMessageDialog(null,"Números Primos são: " + vetorDePrimos);   
    }
    
    public static int[] geradorDeVetor(int n) {
        int[] vetorGeradoEPreenchido = new int[n];
        for (int i = 0; i < n; i++) {
            vetorGeradoEPreenchido[i] = i + 1;
        }
        return vetorGeradoEPreenchido;
    }

    private static boolean verificadorPrimo(int numeroDoVetor) {
        for (int j = 2; j < numeroDoVetor; j++) {
            if (numeroDoVetor % j == 0)
                return false;   
        }
        return true;
    }

}
