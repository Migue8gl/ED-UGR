- La implementación de las clases ruta, almacen de rutas y punto están divididas en ficheros
.h y .cpp

- Al final no he usado el multimap porque considero que hace menos legible algunos métodos,
 además la función de borrado se hace menos eficiente al tener que hacer bucles 
de búsqueda entre las distintas rutas que tengan misma clave. Si bien es cierto que 
GetRutasConPunto no es eficiente al tener dos bucles anidados, borrado e insertar sí, y quedan
mucho más reducidos. Además veo más coherente usar una lista secuencial para almacenar los puntos
más que un multimap, que además los ordena modificando la ruta. Otra opción sería usar las dos, pero entonces para las rutas utilizas el doble de almacenamiento.
