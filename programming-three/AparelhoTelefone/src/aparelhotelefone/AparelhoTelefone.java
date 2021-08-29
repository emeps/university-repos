/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aparelhotelefone;

/**
 *
 * @author emeps
 */
public class AparelhoTelefone {

    public static void main(String[] args) {
        Telefone Motorola = new Telefone(1,"ABC123","MesaTel",0.5f, new Dimensoes(10f,10f,0.5f));

        SemFio SangueSuga = new SemFio(11f, 2400f,100,1,"ABC123",0.76f, "MesaTel",new Dimensoes(10f,10f,0.5f));
        
        Motorola.imprimirDadosTelefone();
    }
    

}
