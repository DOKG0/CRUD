# Aplicación de Gestión de Vehículos en consola (CRUD)

## Descripción

Este proyecto consiste en una aplicación en **C++** que interactúa con una base de datos **MySQL** llamada `vehículo`. La aplicación proporciona un menú de opciones para realizar diversas operaciones en la base de datos, como ingresar, eliminar, modificar, consultar y listar registros.

El sistema se enfoca en gestionar información sobre vehículos almacenados en la tabla `auto`, realizando verificaciones de existencia y mostrando mensajes de error cuando sea necesario.

---

## Funcionalidades

El menú de la aplicación ofrece las siguientes opciones:

1. **Ingreso de Datos**: Permite ingresar nuevos registros en la tabla. Si el registro ya existe, muestra los datos y emite un mensaje de error.
   
2. **Eliminación de Datos**: Solicita un campo clave para verificar la existencia de un registro. Si el registro existe, muestra los datos y pregunta si desea eliminarlo. Si no existe, muestra un mensaje de error.
   
3. **Modificación de Datos**: Solicita un campo clave para verificar la existencia del registro. Si existe, muestra los datos y permite modificar los campos no claves. Si no existe, muestra un mensaje de error.

4. **Consulta de Datos**: Solicita un campo clave y verifica si el registro existe. Si es encontrado, muestra los datos correspondientes; de lo contrario, muestra un mensaje de error.

5. **Listado de Datos**: Muestra todos los registros de la tabla en formato de columna. Los datos pueden ser ordenados si se desea.

6. **Finalizar Programa**: Cierra la aplicación.

---

## Tecnologías Utilizadas

- **Lenguaje de Programación**: C++
- **Base de Datos**: MySQL
- **Conexión a Base de Datos**: MySQL Connector para C++

---

## Instalación

### Requisitos Previos
- Tener instalado un compilador de C++
- Tener instalado **MySQL** en tu sistema.
- Tener configurado **MySQL Connector para C++**.

### Pasos de Instalación

1. Clona o descarga este repositorio:

   ```bash
   git clone https://github.com/DOKG0/CRUD.git
