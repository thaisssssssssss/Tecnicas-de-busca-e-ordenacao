public class Veiculo{
    private String placa;
    private String cor;
    private String ano;
    private String proprietario;

    public void setPlaca(String _placa){
        this.placa = _placa;
    }

    public String getPlaca(){
        return placa;
    }

    public void setCor(String _cor){
        this.cor = _cor;
    }

    public String getCor(){
        return cor;
    }

    public void setAno(String _ano){
        this.ano = _ano;
    }

    public String getAno(){
        return ano;
    }

    public void setProprietario(String _proprietario){
        this.proprietario = _proprietario;
    }

    public String getProprietario(){
        return proprietario;
    }

    //metodo construtor
    public Veiculo(String _placa, String _cor, String _ano, String _proprietario){
        setPlaca(_placa);
        setCor(_cor);
        setAno(_ano);
        setProprietario(_proprietario);
    }

    public void exibeDados(){
        System.out.printf("Placa: %s, Cor: %s, Ano: %s, Proprietario: %s", placa, cor, ano, proprietario);
    }
}