package aparelhotelefone;

public class SemFio extends Telefone {

    private float frequenciaDoAparelho;
    private float distanciaDoAparelho;
    private int canaisDeOperacao;

    public SemFio(float frequenciaDoAparelho, float distanciaDoAparelho, int canaisDeOperacao, int codigo,
            String numeroSerie, float peso, Dimensoes dimensoes) {
        super(codigo, numeroSerie, peso, dimensoes);
        this.frequenciaDoAparelho = frequenciaDoAparelho;
        this.distanciaDoAparelho = distanciaDoAparelho;
        this.canaisDeOperacao = canaisDeOperacao;
    }

    SemFio(float f, float f0, int i, int i0, String abC123, float f1, String mesaTel, Dimensoes dimensoes) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    public void imprimirDadosTelefoneSemFio() {
        System.out.println("Frequência de Operações: " + this.frequenciaDoAparelho);
        System.out.println("Canais de Operação: " + this.canaisDeOperacao);
        System.out.println("Distância de Operação: " + this.distanciaDoAparelho);
    }
}
