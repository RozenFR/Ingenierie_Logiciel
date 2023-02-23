package form.model;

import form.visitor.VisitorForm;

public abstract class Form {
    /**
     * Fonction abstraite servant à customiser les fonctionnalités de la classe Forme
     * @param vf Le visiteur fonctionnel
     */
    abstract void accept(VisitorForm vf);
}
