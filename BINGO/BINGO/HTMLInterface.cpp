#include"HTMLInterface.h"

HTMLInterface::HTMLInterface() {
	td = Node("td");
	td.SetAttribute("id", "square");
	styleSheets();
	doc.AddNodeToBody(Node("h1").SetContent("BINGO"));
}

void HTMLInterface::styleSheets() {
	Node css("link");
	css.SetAttribute("rel", "stylesheet");
	css.SetAttribute("rev", "stylesheet");
	css.SetAttribute("href", "bingo-card.css");
	doc.AddNodeToHead(css);
}

void HTMLInterface::serialize(list<Jugador*> jugadores, int bolita) {

	doc.AddNodeToBody(Node("h2").SetContent("Tombola: " + to_string(bolita)));

	string titulo[5] = { "B","I","N","G","O" };
	Node trTitulo("tr");
	Node th("th");

	for (size_t i = 0; i < 5; i++)
	{
		th.SetContent(titulo[i]);
		trTitulo.AppendChild(th);
	}

	for each (Jugador* var in jugadores)
	{
		doc.AddNodeToBody(Node("h3").SetContent(" JUGADOR " + to_string(var->getId())));

		vector<Carton*> c = var->getCartones();

		for each (Carton* var in c)
		{
			vector<Columna*> columnas = var->getColumnas();
			Node table("table");
			table.AppendChild(trTitulo);

			for (int i = 0; i < 5; i++)
			{
				Node tr("tr");

				for (int j = 0; j < 5; j++)
				{
					if (columnas[j]->obtenerPorFila(i + 1)->dato != 0) {
						td.SetContent(to_string(columnas[j]->obtenerPorFila(i + 1)->dato));
					}
					else {
						td.SetContent("X");
					}
					tr.AppendChild(td);
				}
				table.AppendChild(tr);
			}
			doc.AddNodeToBody(table);
			doc.AddNodeToBody(Node("br"));
		}
	}
}

void HTMLInterface::write(int idGanador) {
	doc.AddNodeToBody(Node("h2").SetContent("EL JUGADOR GANADOR ES:  " + to_string(idGanador)));
	doc.WriteToFile("index.html", Readability::MULTILINE);
}