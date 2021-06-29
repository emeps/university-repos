/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lista.pkg10;

import javax.swing.JOptionPane;

/**
 *
 * @author emeps
 */
public class Lista10 {

    /**
     * @param args the command line arguments
     */
    public static float calcSoma(float primeiroNumero, float segundoNumero){
        return (primeiroNumero + segundoNumero);
    }

    public static float calcSubtracao(float primeiroNumero, float segundoNumero){
        return (primeiroNumero - segundoNumero);
    }

    public static float calcMultiplicacao(float primeiroNumero, float segundoNumero){
        return (primeiroNumero * segundoNumero);
    }

    public static float calcDivisao(float primeiroNumero, float segundoNumero){
        return (primeiroNumero / segundoNumero);
    }

    public static String menuSelectCalc(){
        String[] opcaoSelecao = {"Soma", "Subtracao", "Multiplicacao", "Divisao"};
        String opcaoUser = (String)JOptionPane.showInputDialog(null, "Selecione uma das opcao abaixo:","Bem Vindo!", JOptionPane.QUESTION_MESSAGE, null,opcaoSelecao,opcaoSelecao[3]);
        return opcaoUser;
    }

    public static String displayCalc(String opcaoUser, float operacaoCalculadora){
        JOptionPane.showMessageDialog(null, "Operacação escolhida é: " + opcaoUser + ".\nResultado: "+ operacaoCalculadora);
        return null;
    }
    public static float operacaoCalc(String opcaoUser, float primeiroNumero, float segundoNumero){
        if("Soma".equals(opcaoUser))
            return calcSoma(primeiroNumero, segundoNumero);
        if("Subtracao".equals(opcaoUser))
            return calcSubtracao(primeiroNumero, segundoNumero);
        if("Multiplicacao".equals(opcaoUser))
            return calcMultiplicacao(primeiroNumero, segundoNumero);
        if("Divisao".equals(opcaoUser)){
            if(segundoNumero == 0){
                JOptionPane.showMessageDialog(null, "Operação Inválida!");
                return 0;
            }
            else
                return calcDivisao(primeiroNumero, segundoNumero);
        }
        return 0;
    }
    public static void main(String[] args) {
        // TODO code application logic here

        float primeiroNumero = Float.parseFloat(JOptionPane.showInputDialog(null, "Digite o primeiro número.", "Primeiro Número"));
        float segundoNumero = Float.parseFloat(JOptionPane.showInputDialog(null, "Digite o segundo número.", "Segundo Número"));
        String selectUser = menuSelectCalc();
        float numeroCalculado = operacaoCalc(selectUser, primeiroNumero, segundoNumero);
        displayCalc(selectUser, numeroCalculado);
    }
    
}
