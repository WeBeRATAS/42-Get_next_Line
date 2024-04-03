# 42-Get_next_Line
Get Next line de 42

Érase una vez un pescador curioso llamado Alex. Le tocó un trabajo complicado en el acuario: ¡vaciarlo usando sólo un vaso pequeño! El acuario era enorme y no tenía idea de qué peces había dentro ni cuántos. Pero Alex estaba decidido a triunfar.

Con su pequeña taza, comenzó a sacar agua y a ponerla en un recipiente de cultivo. Cada vez que pescaba un pez, lo enviaba felizmente a los visitantes, como si devolviera un sedal. Pero había un problema: no sabía qué tan grande era el acuario ni cuántos peces había allí.

Mientras Alex continuaba, se enfrentó a una decisión difícil. ¿Debería usar una taza grande para pescar más peces a la vez, pero arriesgarse a hacer malabarismos con ellos? ¿O debería limitarse a una taza pequeña, hacer más viajes pero manteniéndolo simple? A pesar de las incertidumbres, Alex se mantuvo flexible y creativo, adaptándose al desafío.

Cada pez que capturaba era como encontrar una nueva línea en un archivo misterioso. Y a pesar de todo, Alex descubrió el placer de resolver problemas en el mundo de la programación a los 42 años.

Vamos, basta de soñar con la taza, los peces y el acuario azul profundo.✨ 💫


En resumen, los desafíos que enfrentó Alex son:
Tamaño de acuario desconocido:
(Código estable, eficiente y robusto para manejar varios escenarios. En la parte adicional, necesitamos leer desde múltiples archivos fd, de diferentes tamaños)
Alex no sabía el tamaño del acuario (archivo) que tenía que vacío.

Número incierto de peces:
(Código confiable, escalable y optimizado para manejar cualquier número de nuevas líneas)
De manera similar, no tenía idea de cuántos peces (líneas) había en el acuario (archivo). Esta incertidumbre se sumó al desafío, ya que no podía predecir cuándo encontraría el próximo pez.

Compensaciones al elegir el tamaño de copa:
(Elegir BUFFER_SIZE)
Alex enfrentó un dilema al elegir el tamaño de copa. Una copa más grande podría capturar más peces a la vez, pero también podría generar dificultades de manejo cuando se capturan varios peces juntos.

Tamaño de copa limitado pero fijo:
(lo que hace que funcione tanto para caracteres pequeños como grandes y grandes *cup_buffer) La
única herramienta de Alex era una copa pequeña (cup_buffer). Usar una taza pequeña significaba más viajes de ida y vuelta, lo que hacía que la tarea consumiera mucho tiempo.

Ampliación de la cuenca:
(malloc char *basin_buffer)
A medida que el nivel del agua del acuario disminuía, la cuenca necesitaba una expansión constante para almacenar más agua. Ampliar la cuenca manteniendo el agua sin derramarla presentó un desafío.

Extracción de peces uno a la vez:
(devolviendo la primera nueva línea encontrada)
Cuando se capturaron varios peces juntos en la taza, Alex enfrentó el desafío de extraerlos cuidadosamente uno a la vez para evitar mezclarlos antes de enviarlos a los clientes.

Contraer la cuenca :
(free y malloc char *basin_buffer con el tamaño necesario nuevamente)
Una y cada vez que se extraía y devolvía un pez (nueva línea), Alex tenía que contraer el tamaño de la cuenca para ahorrar el agua restante. Esta tarea requirió una gestión cuidadosa para retener cualquier pez que aún pudiera estar presente.

Manejo de varios peces:
(salte la lectura hasta que se extraigan y entreguen todas las nuevas líneas)
Si capturaba varios peces a la vez, tenía que separarlos con cuidado antes de enviarlos a los clientes (enviar líneas de regreso). Esto requirió esfuerzo y atención adicionales.
Vaya… ahora entendemos lo intenso que es el tema.
