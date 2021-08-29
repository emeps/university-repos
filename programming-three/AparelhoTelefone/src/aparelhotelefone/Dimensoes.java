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
public class Dimensoes {
    private float altura;
    private float largura;
    private float profundidade;

    public Dimensoes(float altura, float largura, float profundidade) {
        this.altura = altura;
        this.largura = largura;
        this.profundidade = profundidade;
    }
    
    public void imprimirDadosDimensoes(){
        System.out.println("Altura: "+this.altura);
        System.out.println("Largura: "+this.largura);
        System.out.println("Profundidade: "+this.profundidade);
    }
    
}
