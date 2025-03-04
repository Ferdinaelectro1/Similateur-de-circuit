#include "Fil.h"

Fil::Fil()
{}

Fil::Fil(QGraphicsLineItem *line)
{
    m_line = line;
}

//cette fonction permet de dessiner les connexions dans le schema en fonction du deplacement du curseur
//cette fonction assigne toujours la valeur du sommet de la ligne qui est en cours de dessin 
// à l'attributs m_new_origine afin de pouvoir tracer de nouvelle connexion partant de ce sommet
void Fil::moveLine(QPointF origine,QPointF curseur,bool isMove)
{
    m_origine = origine;
    m_curseur = curseur;
    if(isMove)
    {
        qreal dx = std::abs(origine.x() - curseur.x());
        qreal dy = std::abs(origine.y() - curseur.y());
        if(dx > dy)
        {
            m_line->setLine(origine.x(),origine.y(),curseur.x(),origine.y());
            m_new_origine = QPointF(m_curseur.x(),m_origine.y());

        }
        else
        {
            m_line->setLine(origine.x(),origine.y(),origine.x(),curseur.y());
            m_new_origine = QPointF(m_origine.x(),m_curseur.y());
        }
    }
}

//cette fonction permet de retourner le nouveau point d'origine , elle est appelé à chaque clic
QPointF Fil::get_new_origine()
{
    return m_new_origine;
}