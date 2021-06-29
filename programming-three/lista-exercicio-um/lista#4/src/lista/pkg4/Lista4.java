/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lista.pkg4;

import java.util.Arrays;
import javax.swing.JOptionPane;

/**
 *
 * @author emeps
 */
public class Lista4 {

    /**
     * @param args the command line arguments
     */
    
    public static void main(String[] args) {
        // TODO code application logic here
        int[][] matriz = new int[10][10];
        for(int i =0; i< 10; i++){
            for(int j =0; j< 10; j++){
                if(i==j)
                    matriz[i][j] = 1;
                else
                    matriz[i][j] = 0;
            }
        }
        for(int i =0; i< 10; i++){
            for(int j =0; j< 10; j++){
                System.out.print(matriz[i][j]);
            }
            System.out.print("\n");
        }
    }
          
}
