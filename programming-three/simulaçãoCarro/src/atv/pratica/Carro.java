/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package atv.pratica;

import javax.swing.JOptionPane;

/**
 *
 * @author emeps
 */
public class Carro {
    private String modelo;
    private String cor;
    private int ano;
    private Marca marca;
    private String chassi;
    private String proprietario;
    private int velocidadeMaxima;
    private int velocidadeAtual;
    private int numeroMarchas;
    private int marchaAtual;
    private float volumeCombustivel;
    private float capacidadeCombustivel;
    private String direcaoTrajeto;

    public Carro(String modelo, String cor, int ano, Marca marca, String chassi, String proprietario,
            int velocidadeMaxima, int velocidadeAtual, int numeroMarchas, int marchaAtual, float volumeCombustivel,
            float capacidadeCombustivel, String direcaoTrajeto) {
        this.modelo = modelo;
        this.cor = cor;
        this.ano = ano;
        this.marca = marca;
        this.chassi = chassi;
        this.proprietario = proprietario;
        this.velocidadeMaxima = velocidadeMaxima;
        this.velocidadeAtual = velocidadeAtual;
        this.numeroMarchas = numeroMarchas;
        this.marchaAtual = marchaAtual;
        this.volumeCombustivel = volumeCombustivel;
        this.capacidadeCombustivel = capacidadeCombustivel;
        this.direcaoTrajeto = direcaoTrajeto;
    }
    // TODO: Método Acelerar
    public void aumentarVelocidade() {
        if (this.velocidadeAtual >= this.velocidadeMaxima)
            this.velocidadeAtual = this.velocidadeMaxima;
        else
            this.velocidadeAtual += 5;
    }
    // TODO: Método Desacelerar
    public void diminuirVelocidade() {
        if (this.velocidadeAtual <= 0)
            this.velocidadeAtual = 0;
        else
            this.velocidadeAtual -= 4;
    }
    // TODO: Método Trajeto
    public void setTrajeto(String trajetoCircuito) {
        this.direcaoTrajeto = trajetoCircuito;
    }
    // TODO: Método Dirigir
    public void setDirigir(int velocidade, String direcao) {
        setTrajeto(direcao);
        if (direcao != "reta"){
            while (this.velocidadeAtual >= velocidade){
                diminuirVelocidade();                
                trocaAutomaticaMarcha(velocidade);
            }
            if(this.velocidadeAtual <= 0){ 
                diminuirVelocidade();
                trocaAutomaticaMarcha(velocidade);
            }
        }
        else
            while (this.velocidadeAtual <= velocidade){
                aumentarVelocidade();
                trocaAutomaticaMarcha(velocidade);
            }
            if(this.velocidadeAtual < velocidade){
                aumentarVelocidade();
                trocaAutomaticaMarcha(velocidade);
            }
                
    }

    private void trocaAutomaticaMarcha(int velocidade){ 
        if(velocidade <=0 )
            this.marchaAtual = 0;
        if(velocidade >0 && velocidade < 7)
            trocaDeMarcha(1);
        if(velocidade >=7 && velocidade < 17)
            trocaDeMarcha(2);
        if(velocidade >=17 && velocidade < 40)
            trocaDeMarcha(3);
        if(velocidade >=40 && velocidade < 80)
            trocaDeMarcha(4);
        if(velocidade >=80 && velocidade < 130)
            trocaDeMarcha(5);
        if(velocidade >=130)
            trocaDeMarcha(this.numeroMarchas); 
    }

    public void direcaoTrajetoRealizado(){
        System.out.println("-----------------------------------------------------------------");
        System.out.println("|> Direção: " + this.direcaoTrajeto);
        System.out.println("|> Velocidade: " + this.velocidadeAtual+"km/h");
        System.out.println("|> Marcha Atual: " + this.marchaAtual);
        System.out.println("-----------------------------------------------------------------");
    }
    // TODO: Método troca de marcha
    public void trocaDeMarcha(int novaMarcha) {
        if (novaMarcha >= 1 && novaMarcha <= 6) {
            int diferencaMarcha = Math.abs((this.marchaAtual + 1 ) - novaMarcha);
            if (diferencaMarcha <= 2 && diferencaMarcha >= 0) {
                if (this.direcaoTrajeto == "reta") {
                    while(this.marchaAtual != novaMarcha)
                        this.marchaAtual += 1;
                }else{
                    while(this.marchaAtual != novaMarcha)
                        this.marchaAtual -=1;
                }
            } else 
                JOptionPane.showMessageDialog(null, "Impossivel realizar a troca de marcha");
        } else
            JOptionPane.showMessageDialog(null, "Sistema de marchas incorretas.");
    }    
    //TODO: Método Autonomia
    public void autonomiaDoCarro(float consumoMedio){
        System.out.println("|> Autonomia do veiculo é de: " + (this.volumeCombustivel*consumoMedio) + "km");
        System.out.println("|> Consumo Médio é de: " + consumoMedio + "km/L");
        verificarQuantidadeDeCombustivel();
    }
    //TODO: Método impressao combustivel
    public void verificarQuantidadeDeCombustivel(){
        System.out.println("|> Capacidade Máxima de Combustível: " + this.capacidadeCombustivel + " litros\n"+ 
        "|> Volume Atual de Combustível: " +this.volumeCombustivel + " litros");
    }
    public void infoVeiculo(){
        System.out.println("---------------- Informações do Veiculo -------------------------");
        System.out.println("|> Modelo: " + this.modelo);
        System.out.println("|> Cor: " + this.cor);
        System.out.println("|> Ano: " + this.ano);
        System.out.println("|> Marca: " + marca.getNome());
        System.out.println("|> Número do Modelo: " + marca.getNumeroDeModelo());
        System.out.println("|> Ano de Lançamento: " + marca.getAnoLancamento());
        System.out.println("|> Código Identificador: " + marca.getCodigoIdentificador());
        System.out.println("|> Chassi: " + this.chassi);
        System.out.println("|> Proprietário: " + this.proprietario );
        System.out.println("|> Velocida Máxima: " + this.velocidadeMaxima +" km/h");
        System.out.println("|> Número de Marchas: " + this.numeroMarchas );
        verificarQuantidadeDeCombustivel();
        System.out.println("-----------------------------------------------------------------");
    }
}
