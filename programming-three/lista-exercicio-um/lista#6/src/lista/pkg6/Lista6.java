 /*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lista.pkg6;

import java.util.Random;

import javax.swing.JOptionPane;

/**
 *
 * @author emeps
 */
public class Lista6 {

    /**
     * @param args the command line arguments
     */
    public static int[] vetorOrdenadoFuncao(int[] vetorPseudoAleatorio){
        int auxiliar = 0;
        for( int i = 0; i < vetorPseudoAleatorio.length; i++){
            for( int j = 0; j< vetorPseudoAleatorio.length - 1; j++){
                if(vetorPseudoAleatorio[j] > vetorPseudoAleatorio[j+1]){
                    auxiliar = vetorPseudoAleatorio[j];
                    vetorPseudoAleatorio[j] = vetorPseudoAleatorio[j+1];
                    vetorPseudoAleatorio[j+1] = auxiliar;
                }
            }
        }
        return vetorPseudoAleatorio;
    }
    public static void main(String[] args) {
        // TODO code application logic here
        Random random = new Random();
        int[] vetorPseudoAleatorio = new int[10];

        for (int i = 0; i< vetorPseudoAleatorio.length; i++)
            vetorPseudoAleatorio[i] =  random.nextInt(100);

        int[] vetorOrdenado = vetorOrdenadoFuncao(vetorPseudoAleatorio);
        String vetorOrdenadoString = " ";
        for (int i = 0; i< vetorPseudoAleatorio.length; i++)
            vetorOrdenadoString += " " + String.valueOf(vetorOrdenado[i]) + ",";
        JOptionPane.showMessageDialog(null, "Vetor ordenado: " + vetorOrdenadoString);
    }
    
}
