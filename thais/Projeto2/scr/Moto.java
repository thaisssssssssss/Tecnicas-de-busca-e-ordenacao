 public class Moto extends Veiculo{
    private String modelo;

    public void setModelo(String _modelo){
        this.modelo = _modelo;
    }

    public String getModelo(){
        return modelo;
    }

    public Moto(String _modelo, String _placa, String _cor, String _ano, String _proprietario){
        super(_placa, _cor, _ano, _proprietario);
        setModelo(_modelo);
    }

    public void exibeDadosMoto(){
        System.out.printf("Modelo Moto: %s, ", modelo);
        super.exibeDados();
    }
} 

