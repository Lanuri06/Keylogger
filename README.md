# Keylogger
Mis tarea para la materia de Seguridad Informatica c:
Keylogger en C

Este proyecto es un keylogger básico escrito en C. El programa captura las pulsaciones de teclas en un sistema Linux y las registra en un archivo de log. Este keylogger se ha creado únicamente con fines educativos y debe usarse en entornos controlados.
Tabla de Contenidos

    Requisitos
    Instrucciones de Uso
    Supuestos del Programa
    Casos de Uso
    Advertencias Legales

Requisitos

    Sistema Operativo: Linux (probado en Ubuntu)
    Compilador: GCC
    Permisos: El programa requiere permisos de superusuario para acceder al dispositivo de entrada del teclado.

Instrucciones de Uso
1. Compilación

Para compilar el programa, asegúrate de que tienes GCC instalado. Luego, abre una terminal y ejecuta el siguiente comando:

gcc Keylogger.c -o Keylogger

2. Ejecución

Como el programa necesita acceder a dispositivos de entrada que requieren permisos elevados, debes ejecutarlo como superusuario:

sudo ./Keylogger

El keylogger comenzará a ejecutarse y registrará todas las pulsaciones de teclas en un archivo de log ubicado en /tmp/keylogger.txt.
3. Ver el Log

Puedes ver el contenido del archivo de log en cualquier momento ejecutando:

cat /tmp/keylogger.txt

4. Detener el Programa

Para detener el keylogger, simplemente presiona Ctrl + C en la terminal donde se está ejecutando. También puedes matar el proceso utilizando comandos como kill si lo has ejecutado en segundo plano.
Supuestos del Programa

    Dispositivo del Teclado: El programa asume que el dispositivo de entrada del teclado está correctamente identificado y accesible en /dev/input/eventX.
    Formato de Log: El archivo de log registrará cada tecla presionada en un formato legible. Las teclas especiales como ENTER, BACKSPACE, y SHIFT están representadas por etiquetas como [ENTER] o [SHIFT].
    Entorno Controlado: El programa está diseñado para ejecutarse en un entorno controlado, como una máquina virtual para fines educativos.

Casos de Uso

    Educación y Pruebas de Seguridad: Este keylogger es útil para entender cómo funcionan los keyloggers y cómo se puede proteger un sistema contra ellos.
    Auditoría de Seguridad: Puede utilizarse en un entorno de prueba para verificar la seguridad de un sistema y estudiar la detección de keyloggers.
    Desarrollo de Software: Los desarrolladores pueden utilizar este código como base para crear herramientas de monitoreo de teclas en sistemas Linux.

Advertencias Legales

Este software ha sido desarrollado únicamente con fines educativos y no debe ser utilizado para monitorear teclados sin el consentimiento del usuario. El uso de keyloggers en entornos no autorizados es ilegal y contrario a la ética. El autor no se responsabiliza por el uso indebido de este software.

## Créditos

Este proyecto no hubiera sido posible sin la ayuda y las herramientas de las siguientes personas y recursos:

- **[ChatGPT](https://www.openai.com/)** - Asistencia en la creación del README.
- **[Documentación de Linux](https://www.kernel.org/doc/html/latest/input/input-programming.html)** - Referencia utilizada para comprender el manejo de eventos de entrada.
- ** https://itsfoss.com/es/escribir-compilar-ejecutar-programa-c-ubuntu/** - Referencia usada para compilar en Ubuntu
- **Stack Overflow - Plataforma de preguntas y respuestas que proporcionó soluciones a problemas específicos durante el desarrollo.
- ** https://itsfoss.com/es/escribir-compilar-ejecutar-programa-c-ubuntu/ ** - Referemcoa para compilar en C en Ubuntu
- **Clase del profesor DANIEL FERNANDO PALMA LOPEZ de Seguridad Informatica
- **Companero de clase RYAN MONROY PICAZO que me enseno a usar mas ubuntu
