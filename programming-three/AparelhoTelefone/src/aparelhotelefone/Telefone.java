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
public class Telefone {
    private int codigo;
    private String numeroSerie;
    private String modelo;
    private float peso;
    private Dimensoes dimensoes;

    public Telefone(int codigo, String numeroSerie, float peso, Dimensoes dimensoes) {
        this.codigo = codigo;
        this.numeroSerie = numeroSerie;
        this.peso = peso;
        this.dimensoes = dimensoes;
    }

    Telefone(int i, String abC123, String mesaTel, float f, Dimensoes dimensoes) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
    
    public void imprimirDadosTelefone(){
        System.out.println("Codigo: "+this.codigo);
        System.out.println("Número de Série: "+this.numeroSerie);
        System.out.println("Modelo: "+this.modelo);
        System.out.println("Peso: "+this.peso);
        this.dimensoes.imprimirDadosDimensoes();
    }   
    
}
