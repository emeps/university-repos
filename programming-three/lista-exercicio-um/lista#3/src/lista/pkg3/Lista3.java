/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lista.pkg3;



/**
 *
 * @author emeps
 */
public class Lista3 {
    
    public static int[] vetorPrimo(int n){
        int primos[] = new int[n];
        
        for(int i = 0; i< n; i++)
            primos[i] = i + 1;
        
        return primos;
    }
    public static String verificarPrimo(int[] primos){
        String numerosPrimos = "";
        int contador = 0;
        for(int j = 1; j<=primos.length; j++){
            for(int i = 1; i<=primos.length; i++){
                if(primos[i]%j==0){
                    contador++;
                }
            }
            if(contador == 2){
                numerosPrimos += " " + String.valueOf(primos[j]);
            }
        }
        return numerosPrimos;
    }
            
    public static void imprimirVetor(String primos){
        // TODO Montar o vetor em String
        System.out.printf(primos);
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        String resultado = verificarPrimo(vetorPrimo(20));
        imprimirVetor(resultado);
        
    }

    @Override
    public SourceVersion getSupportedSourceVersion() {
        return SourceVersion.RELEASE_16;
    }
    
}
