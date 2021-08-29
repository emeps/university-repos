/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package atv.pratica;


public class AtvPratica {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Marca marca = new Marca("Chevrolet", "1F3FO49", 2015, "CHEV2015F509BR");
        Carro carro11 = new Carro(
            "Cruze",
            "Branco",
            2015,
            marca,
            "092KH3941",
            "Emerson Patryck",
            270,
            0,
            6,
            0,
            75f,
            75f,
            "stand-by"
        );   

        System.out.println("\n\n\n");
        carro11.infoVeiculo();
        carro11.autonomiaDoCarro(14.6f);

        
        System.out.println("-----------------------------------------------------------------");
        System.out.println("\n\nTeste Circuito");
        System.out.println("Seguimento B - M");
        carro11.setDirigir(20, "reta");
        carro11.direcaoTrajetoRealizado();
        System.out.println("Seguimento D");
        carro11.setDirigir(16, "esquerda");
        carro11.direcaoTrajetoRealizado();
        System.out.println("Seguimento E");
        carro11.setDirigir(20, "direita");
        carro11.direcaoTrajetoRealizado();
        System.out.println("Seguimento N - H");
        carro11.setDirigir(24, "reta");
        carro11.direcaoTrajetoRealizado();
        System.out.println("Seguimento K");
        carro11.setDirigir(20, "esquerda");
        carro11.direcaoTrajetoRealizado();
        System.out.println("Seguimento F - G - H");
        carro11.setDirigir(40, "reta");
        carro11.direcaoTrajetoRealizado();
        System.out.println("Chegada");
        carro11.setDirigir(0, "standby");
        carro11.direcaoTrajetoRealizado();
        
    }

}
