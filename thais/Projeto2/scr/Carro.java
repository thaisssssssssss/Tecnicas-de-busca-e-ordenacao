 public class Carro extends Veiculo{
    private String modelo;

    public void setModelo(String _modelo){
        this.modelo = _modelo;
    }

    public String getModelo(){
        return modelo;
    }

    public Carro(String _modelo, String _placa, String _cor, String _ano, String _proprietario){
        super(_placa, _cor, _ano, _proprietario);
        setModelo(_modelo);
    }

    public void exibeDadosCarro(){
        System.out.printf("Modelo Carro: %s, ", modelo);
        super.exibeDados();
    }
} 
