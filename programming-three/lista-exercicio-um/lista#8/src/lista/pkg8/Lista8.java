/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lista.pkg8;

import javax.swing.JOptionPane;

/**
 *
 * @author emeps
 */
public class Lista8 {

    public static String opcaoBanco(){
        String[] userOptions = {"0","1","2" };
        String opcao = (String)JOptionPane.showInputDialog(null, "Selecione uma das opcao abaixo:\n0 - Debito\n1 - Credito\n2 - Para air","Bem Vindo!", JOptionPane.QUESTION_MESSAGE, null,userOptions,userOptions[2]);
        return opcao;
    }
    public static float operacaoBanco (String opcao){
        float saldo = 0;
        while(!"2".equals(opcao)){
            if("0".equals(opcao)){
                saldo = operacaoDebito(saldo);
                opcao = opcaoBanco();
            }
            if("1".equals(opcao)){
               saldo =  operacaoCredito(saldo);
               opcao = opcaoBanco();
            }
            if("2".equals(opcao))
                return saldo;
        }
        return 0;
    }

    public static float operacaoDebito(float saldo){
        if(saldo <= 0){
             JOptionPane.showMessageDialog(null, "Saldo insuficiente. Realize outra operacao");
            return saldo;
        }
        else{
            float debitoConta = Float.parseFloat(JOptionPane.showInputDialog(null, "Valor a ser retirado", "Debito"));
            if(debitoConta> saldo){
                JOptionPane.showMessageDialog(null, "Saldo insuficiente. Realize outra operacao");
            return saldo;
            }else
                return (saldo - debitoConta);
        }
    }

    public static float operacaoCredito(float saldo){
        float deposito = Float.parseFloat(JOptionPane.showInputDialog(null, "Valor a ser Depositado", "Credito"));
        return saldo + deposito;
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        float saldo = operacaoBanco(opcaoBanco());
        
        JOptionPane.showMessageDialog(null, "Seu saudo e: " + saldo + " reais");
    }
    
}
