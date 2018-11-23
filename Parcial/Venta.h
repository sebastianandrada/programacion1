typedef struct
{
    int id;
    char fechaVenta[128];
    char codigo[128];
    int cantidad;
    float precioUnitario;
    char cuit[128];
} Venta;

 Venta* Venta_new();
void Venta_delete();
 //Venta* Venta_newConParametros(int id,char* fechaVenta,char* codigo,int cantidad,float precioUnitario,char* cuit);
 Venta* Venta_newConParametros(char* strid,char* fechaVenta,char* codigo,char* strcantidad,char* strprecioUnitario,char* cuit);

int Venta_setId( Venta* this,int id);
int Venta_getId( Venta* this,int* id);

int Venta_setFechaVenta( Venta* this,char* fechaVenta);
int Venta_getFechaVenta( Venta* this,char* fechaVenta);

int Venta_setCodigo( Venta* this,char* codigo);
int Venta_getCodigo( Venta* this,char* codigo);

int Venta_setCantidad( Venta* this,int cantidad);
int Venta_getCantidad( Venta* this,int* cantidad);

int Venta_setPrecioUnitario( Venta* this,float precioUnitario);
int Venta_getPrecioUnitario( Venta* this,float* precioUnitario);

int Venta_setCuit( Venta* this,char* cuit);
int Venta_getCuit( Venta* this,char* cuit);

int venta_printVenta(void* p);
int venta_totalesVendidas(void* p);
int venta_ventasMayorA10000(void* p);
int venta_ventasMayorA20000(void* p);
int venta_ventasTvLCDs(void* p);
