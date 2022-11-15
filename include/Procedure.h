const int MAX_STEPS = 5;
const int MAX_DESCRIPTION_LENGTH = 30;
class Procedure
{
public:
    Procedure(){};
    char *get_text()
    {
        return this->procedure_description[current_step];
    }
    void next()
    {
        if (!this->is_last())
        {

            this->current_step++;
        }
    }
    bool is_last()
    {
        return this->current_step >= MAX_STEPS;
    }

private:
    int current_step = 0;
    char procedure_description[MAX_STEPS + 1][MAX_DESCRIPTION_LENGTH] = {
        "Paso 1", "Paso 2", "Paso 3", "Paso 4", "Paso 5", "FIN"};
};