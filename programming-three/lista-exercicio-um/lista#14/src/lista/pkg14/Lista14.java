/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lista.pkg14;

import javax.swing.JOptionPane;

/**
 *
 * @author emeps
 */
public class Lista14 {

    /**
     * @param args the command line arguments
     */

    public static float maiorNota(String[] todasAsNotasDosAlunos){
        float maiorNotaAluno = 0;
        int contador = 0;
        while(contador != todasAsNotasDosAlunos.length){
            if(maiorNotaAluno < Float.parseFloat(todasAsNotasDosAlunos[contador]))
                maiorNotaAluno = Float.parseFloat(todasAsNotasDosAlunos[contador]);
            contador +=1;
        }
        return maiorNotaAluno;
    }
    public static float menorNota(String[] todasAsNotasDosAlunos){
        float menorNotaAluno = 10;
        int contador = 0;
        while(contador != todasAsNotasDosAlunos.length){
            if(menorNotaAluno > Float.parseFloat(todasAsNotasDosAlunos[contador]))
                menorNotaAluno = Float.parseFloat(todasAsNotasDosAlunos[contador]);
            contador +=1;
        }
        return menorNotaAluno;
    }
    public static float mediaNota(String[] todasAsNotasDosAlunos){
        float mediaSala = 0;
        int contador = 0;
        while(contador != todasAsNotasDosAlunos.length){
            mediaSala += Float.parseFloat(todasAsNotasDosAlunos[contador]);
            contador +=1;
        }
        return (mediaSala/todasAsNotasDosAlunos.length);
    }
    
    public static void main(String[] args) {
        // TODO code application logic here
        int quantidadesAlunos = Integer.parseInt(JOptionPane.showInputDialog(null, "Insira a quantidade de alunos na classe"));
        String[] todasAsNotasDosAlunos = new String[quantidadesAlunos];
        float notasDosAlunos = 0;
        for (int i = 0; i < quantidadesAlunos; i++ )    
            todasAsNotasDosAlunos[i] = JOptionPane.showInputDialog(null, "Insira as notas dos alunos");
        float maiorNotaRegistrada = maiorNota(todasAsNotasDosAlunos);
        float menorNotaRegistrada = menorNota(todasAsNotasDosAlunos);
        float mediaNotaRegistrada = mediaNota(todasAsNotasDosAlunos);
        JOptionPane.showMessageDialog(null, "A maior nota é: " + maiorNotaRegistrada+"\n"
        + "A menor nota é: " + menorNotaRegistrada+"\n" + "A media das notas é: " + mediaNotaRegistrada+"\n");
    }

    
    
}
