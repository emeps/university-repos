/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lista.pkg5;

import javax.swing.JOptionPane;

/**
 *
 * @author emeps
 */
public class Lista5 {

    public static int[][] registraMatriz(){
        int[][] matriz = new int[4][4];
        for(int i = 0; i< 4;i++){
            for(int j = 0; j< 4;j++){
                matriz[i][j] = Integer.parseInt(JOptionPane.showInputDialog("Insira o valor para armazenar na matriz"));
            }
        }
        return matriz;
    }
    public static int [][] multiplicaMatriz(int[][] matrizA, int[][] matrizB){
        int[][] matrizResultado = new int[4][4];
        int produto = 0;
        for(int i = 0; i< 4;i++){
            for(int j = 0; j< 4;j++){
                produto += (matrizA[i][j]* matrizB[j][i]);
            }
            matrizResultado[i][i] = produto;
            produto = 0;
        }
        
        return matrizResultado;
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int[][] matrizA = new int[4][4];
        int[][] matrizB = new int[4][4];
        JOptionPane.showMessageDialog(null,"Insira o valor para armazenar na matrizA");
        matrizA = registraMatriz();
        JOptionPane.showMessageDialog(null,"Insira o valor para armazenar na matrizB");
        matrizB = registraMatriz();
        int[][] matrizResultado = multiplicaMatriz(matrizA, matrizB);
        for(int i = 0; i< 4;i++){
            for(int j = 0; j< 4;j++){
              System.out.print(matrizResultado[i][j]);
            }
            System.out.print("\n");
        }
           
       
        
    }
    
}
