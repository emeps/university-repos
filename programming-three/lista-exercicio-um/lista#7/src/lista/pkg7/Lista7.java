/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lista.pkg7;

import javax.swing.JOptionPane;

/**
 *
 * @author emeps
 */
public class Lista7 {

    public static float leitorNota(){
        float nota = Float.parseFloat(JOptionPane.showInputDialog("Insira nota do Aluno"));
        return nota;
    }
    public static float mediaAluno(){
        float mediaDoAluno;
        float nota1, nota2, nota3;
        nota1 = leitorNota();
        nota2 = leitorNota();
        nota3 = leitorNota();
        mediaDoAluno = (nota1 + nota2 + nota3)/3;
        return mediaDoAluno;
    }
    public static String aprovacaoAluno(float mediaDoAluno){
        // mediaDoAluno = mediaAluno();
        if(mediaDoAluno >= 7)
            return "Aluno Aprovado";
        if(mediaDoAluno >=4 && mediaDoAluno <7)
            return "Aluno Fazera Prova Final";
        else
            return "Aluno Esta Reprovado";
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        String[] classeResultado = new String[10];
        String resultadoClasse = "";
        for(int i = 0; i < 10; i++){
            JOptionPane.showMessageDialog(null, "Aluno: " + (i + 1), "Aluno", JOptionPane.INFORMATION_MESSAGE);
            classeResultado[i] = aprovacaoAluno(mediaAluno());
        }
        for(int i = 0; i< 10; i++){
            resultadoClasse += "Aluno:" + i +classeResultado[i] + "\n";
        }
        JOptionPane.showMessageDialog(null,"Aprovacao \n" + resultadoClasse, null, JOptionPane.INFORMATION_MESSAGE);
    }
    
}

