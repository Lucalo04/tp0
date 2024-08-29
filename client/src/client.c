#include "client.h"

int main(void)
{

	//log_create ("/home/utnso/Desktop","tp0",1,LOG_LEVEL_INFO);

	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/

	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_config* config;

	/* ---------------- LOGGING ---------------- */

	logger = iniciar_logger();

	// Usando el logger creado previamente

	// Escribi: "Hola! Soy un log"
	//log_info(logger, "Hola! Soy un log");


	/* ---------------- ARCHIVOS DE CONFIGURACION ---------------- */

	config = iniciar_config();

	// Usando el config creado previamente, leemos los valores del config y los 
	// dejamos en las variables 'ip', 'puerto' y 'valor'

	ip = config_get_string_value(config,"IP");
	puerto = config_get_string_value(config,"PUERTO");
	valor = config_get_string_value(config,"CLAVE");

	// Loggeamos el valor de config

	log_info(logger,"%s",ip);
	log_info(logger,"%s",puerto);
	log_info(logger,"%s",valor);

	/* ---------------- LEER DE CONSOLA ---------------- */

	leer_consola(logger);

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// ADVERTENCIA: Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo para poder conectarnos a él

	// // Creamos una conexión hacia el servidor
	// conexion = crear_conexion(ip, puerto);

	// // Enviamos al servidor el valor de CLAVE como mensaje

	// // Armamos y enviamos el paquete
	// paquete(conexion);

	// terminar_programa(conexion, logger, config);

	// /*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// // Proximamente


}

t_log* iniciar_logger(void)
{
	t_log* nuevo_logger = log_create("tp0.log", "Cliente", true, LOG_LEVEL_INFO);
	if (nuevo_logger == NULL)
	{
        abort();
    }
	return nuevo_logger;
}

t_config* iniciar_config(void)
{
	t_config* nuevo_config = config_create("cliente.config");
	if (nuevo_config  == NULL)
	{
        abort();
	}
	return nuevo_config;
}

void leer_consola(t_log* logger)
{

	char* leido;


	// La primera te la dejo de yapa
	// El resto, las vamos leyendo y logueando hasta recibir un string vacío


	while(1)
	{

		leido = readline("> ");
		
		
		if (strcmp(leido,"") == 0)
		{
			log_info(logger,"entre");
			break;
			
		}

		log_info(logger,"%s",leido);

	}
	

	// ¡No te olvides de liberar las lineas antes de regresar!
	free(leido);

}

void paquete(int conexion)
{
	// Ahora toca lo divertido!
	char* leido;
	t_paquete* paquete;

	// Leemos y esta vez agregamos las lineas al paquete


	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!
	free(paquete);
	
}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	log_destroy(logger);
	config_destroy(config);

	/* Y por ultimo, hay que liberar lo que utilizamos (conexion, log y config) 
	  con las funciones de las commons y del TP mencionadas en el enunciado */
}
