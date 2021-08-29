
package atv.pratica;

import javax.swing.JOptionPane;

/**
 *
 * @author emeps
 */
public class Marca {
    private String nome;
    private String numeroDeModelo;
    private int anoDeLancamento;
    private String codigoIdentificador;

    public Marca(String nome, String numeroDeModelo, int anoDeLancamento, String codigoIdentificador) {
        this.nome = nome;
        this.numeroDeModelo = numeroDeModelo;
        this.anoDeLancamento = anoDeLancamento;
        this.codigoIdentificador = codigoIdentificador;
    }
    public String getNome(){
        return this.nome;
    }
    public String getNumeroDeModelo(){
        return this.numeroDeModelo;
    }
    public int getAnoLancamento(){
        return this.anoDeLancamento;
    }
    public String getCodigoIdentificador(){
        return this.codigoIdentificador;
    }
}
