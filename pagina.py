import customtkinter as ctk
from PIL import Image
import os

ctk.set_appearance_mode("light")
ctk.set_default_color_theme("blue")

app = ctk.CTk()
app.geometry("800x600")
app.title("Ventana")

# panel lateral izquierdo en blanco con borde negro
left_panel = ctk.CTkFrame(
    app,
    width=200,
    corner_radius=20,
    fg_color="white",
    border_color="black",
    border_width=2
)
left_panel.pack(side="left", fill="y", padx=10, pady=(60, 10))

# cuadrado al lado del panel izquierdo SIN esquinas redondeadas, más grande
square = ctk.CTkFrame(
    app,
    width=250,   
    height=400,  
    corner_radius=0,
    fg_color="white",
    border_color="black",
    border_width=2
)
square.place(x=220, y=60)

# rectángulo superior como encabezado
header = ctk.CTkFrame(app, height=50, fg_color="#003274", corner_radius=0)
header.place(x=0, y=0, relwidth=1)

# texto "CLAMATIN" en la parte superior izquierda
label_header = ctk.CTkLabel(
    header,
    text="CLAMATIN",
    text_color="white",
    font=ctk.CTkFont(size=16, weight="bold")
)
label_header.place(x=10, y=10)

# 4 botones al lado del texto CLAMATIN
button1 = ctk.CTkButton(header, text="Inicio", fg_color="#003274", text_color="white", hover_color="#0f1f7a", width=80, height=30)
button1.place(x=120, y=10)

button2 = ctk.CTkButton(header, text="Inventario", fg_color="#003274", text_color="white", hover_color="#0f1f7a", width=80, height=30)
button2.place(x=200, y=10)

button3 = ctk.CTkButton(header, text="Ventas", fg_color="#003274", text_color="white", hover_color="#0f1f7a", width=80, height=30)
button3.place(x=280, y=10)

# campo de búsqueda (Entry) a un lado del botón Ventas
search_entry = ctk.CTkEntry(header, placeholder_text="Buscar...", width=150, height=30)
search_entry.place(x=520, y=10)



# Botón circular con símbolo 
circular_button =  ctk.CTkButton(
    app,
    text="+",
    fg_color="#1427b8",
    text_color="white",
    hover_color="#0f1f7a",
    width=50,
    height=50,
    corner_radius=25
)
circular_button.place(relx=1.0, rely=1.0, x=-70, y=-70, anchor="se")

# texto "Filtros" centrado en la parte superior del left_panel
label_filtros = ctk.CTkLabel(
    left_panel,
    text="Filtros",
    text_color="black",
    font=ctk.CTkFont(size=16, weight="bold")
)
label_filtros.place(relx=0.5, y=10, anchor="n")

# texto "Marca de llanta" alineado a la izquierda debajo de "Filtros"
label_marca = ctk.CTkLabel(
    left_panel,
    text="Marca de llanta",
    text_color="black",
    font=ctk.CTkFont(size=14)
)
label_marca.place(x=10, y=50)

# botón desplegable (opciones) debajo de "Marca de llanta"
marca_option = ctk.CTkOptionMenu(
    left_panel,
    values=["Michelin", "Pirelli", "Goodyear", "Continental"],
    width=160
)
marca_option.place(x=10, y=80)

# texto "Modelo" debajo del botón desplegable
label_modelo = ctk.CTkLabel(
    left_panel,
    text="Modelo",
    text_color="black",
    font=ctk.CTkFont(size=14)
)
label_modelo.place(x=10, y=120)

# campo de búsqueda (Entry) debajo de "Modelo"
Nombre_entry = ctk.CTkEntry(
    left_panel,
    placeholder_text="Nombre o codigo de llanta",
    width=160
)
Nombre_entry.place(x=10, y=150)

# texto "Medidas" debajo del campo de búsqueda de modelo
label_medidas = ctk.CTkLabel(
    left_panel,
    text="Medidas",
    text_color="black",
    font=ctk.CTkFont(size=14)
)
label_medidas.place(x=10, y=190)

# campo de entrada para medidas de la llanta
medidas_entry = ctk.CTkEntry(
    left_panel,
    placeholder_text="Ej. 205/55 R16",
    width=160
)
medidas_entry.place(x=10, y=220)

# texto "Ubicación en almacén" debajo de medidas_entry
label_ubicacion = ctk.CTkLabel(
    left_panel,
    text="Ubicación en almacén",
    text_color="black",
    font=ctk.CTkFont(size=14)
)
label_ubicacion.place(x=10, y=260)

# campo desplegable de ubicación
ubicacion_option = ctk.CTkOptionMenu(
    left_panel,
    values=["Pasillo 1", "Pasillo 2", "Bodega A", "Bodega B"],
    width=160
)
ubicacion_option.place(x=10, y=290)

# texto "Fabricantes" debajo del campo de ubicación
label_fabricante = ctk.CTkLabel(
    left_panel,
    text="Fabricantes",
    text_color="black",
    font=ctk.CTkFont(size=14)
)
label_fabricante.place(x=10, y=330)

# campo de entrada de fabricante
fabricante_entry = ctk.CTkEntry(
    left_panel,
    placeholder_text="Nombre fabricante",
    width=160
)
fabricante_entry.place(x=10, y=360)

# texto "Fecha de actualización" debajo del fabricante
label_fecha = ctk.CTkLabel(
    left_panel,
    text="Fecha de actualización",
    text_color="black",
    font=ctk.CTkFont(size=14)
)
label_fecha.place(x=10, y=400)

# campo desplegable de fecha de actualización
fecha_option = ctk.CTkOptionMenu(
    left_panel,
    values=["Última semana", "Último mes", "Últimos 3 meses"],
    width=160
)
fecha_option.place(x=10, y=430)

# botón aplicar filtros al final
aplicar_button = ctk.CTkButton(
    left_panel,
    text="Aplicar filtros",
    fg_color="#003274",
    text_color="white",
    hover_color="#0f1f7a",
    width=160
)
aplicar_button.place(x=10, y=470)

# imagen en el cuadrado, más grande
imagen_llanta = Image.open("llantaa.jpg")
imagen_llanta = imagen_llanta.resize((180, 180))
imagen_ctk = ctk.CTkImage(light_image=imagen_llanta, dark_image=imagen_llanta, size=(180, 180))
imagen_label = ctk.CTkLabel(square, image=imagen_ctk, text="")
imagen_label.place(relx=0.5, rely=0.05, anchor="n")

# texto con la información detallada centrado en el cuadrado
info_text = (
    "Michelin Energy Saver\n"
    "205/55 R16\n"
    "Código-362514\n"
    "Auto/Todo Clima\n"
    "Sucursal Apodaca (8 disponibles)\n"
    "Cantidad- 105 disponibles\n"
    "$3,760 MX"
)

info_label = ctk.CTkLabel(
    square,
    text=info_text,
    text_color="black",
    justify="center",
    font=ctk.CTkFont(size=12)
)
info_label.place(relx=0.5, rely=0.65, anchor="n")

# botón debajo del texto en el cuadrado
ver_mas_button = ctk.CTkButton(
    square,
    text="Editar",
    fg_color="#1427b8",
    text_color="white",
    hover_color="#0f1f7a",
    width=100,
    height=30
)
ver_mas_button.place(relx=0.5, rely=1.0, y=-10, anchor="s")

# texto "Ordenar por" al lado izquierdo del desplegable
label_ordenar = ctk.CTkLabel(
    app,
    text="Ordenar por",
    text_color="black",
    font=ctk.CTkFont(size=14)
)
label_ordenar.place(x=520, y=60)

# botón desplegable de orden de precio
precio_option = ctk.CTkOptionMenu(
    app,
    values=["Precio: mayor a menor", "Precio: menor a mayor", "Popularidad", "Novedades"],
    width=200
)
precio_option.place(x=600, y=60)

app.mainloop()