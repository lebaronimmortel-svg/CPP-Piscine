#include "Character.hpp"

Character::Character(void)
{
    std::cout << "Character default constructor called" << std::endl;

    this->_n_unequiped = 0;
    this->_unequiped = new AMateria*[100];
    for (int i = 0; i < 100; i++)
    {
        this->_unequiped[i] = NULL;
    }

    this->_inventory = new AMateria*[4];
    for (int i = 0; i < 4; i++)
    {
        this->_inventory[i] = NULL;
    }
}

Character::Character(std::string name) : _name(name)
{
    std::cout << "Character constructor called" << std::endl;

    this->_n_unequiped = 0;
    this->_unequiped = new AMateria*[100];
    for (int i = 0; i < 100; i++)
    {
        _unequiped[i] = NULL;
    }
    
    _inventory = new AMateria*[4];
    for (int i = 0; i < 4; i++)
    {
        _inventory[i] = NULL;
    }
}

Character::~Character(void)
{
    std::cout << "Character destructor called" << std::endl;

    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i] != NULL)
            delete _inventory[i];
        _inventory[i] = NULL;
    }

    delete [] _inventory;

    
    for (int i = 0; i < _n_unequiped; i++)
    {
        if (_unequiped[i] != NULL)
            delete _unequiped[i];
        _unequiped[i] = NULL;
    }
    
    delete [] _unequiped;
}


Character::Character(const Character& copy) : _name(copy._name)
{
    std::cout << "Character copy constructor called" << std::endl;

    this->_inventory = new AMateria*[4];
    for (int i = 0; i < 4; i++)
    {
        if (copy._inventory[i] != NULL)
            this->_inventory[i] = copy._inventory[i]->clone();
        else
            this->_inventory[i] = NULL;
    }

    this->_n_unequiped = 0;
    this->_unequiped = new AMateria*[100]; 
    for (int i = 0; i < 100; i++)
    {
        this->_unequiped[i] = NULL;
    }
}

Character&  Character::operator=(const Character& rhs)
{
    std::cout << "Character operator= called" << std::endl;

    if (this != &rhs)
    {
        this->_name = rhs._name;
        for (int i = 0; i < 4; i++)
        {
            if (rhs._inventory[i] != NULL)
            {
                delete this->_inventory[i];
                this->_inventory[i] = rhs._inventory[i]->clone();
            }
        }
        for (int i = 0; i < 100; i++)
        {
            if (rhs._unequiped[i] != NULL)
            {
                delete this->_unequiped[i];
                this->_unequiped[i] = _unequiped[i]->clone();
            }
        }
        this->_n_unequiped = rhs._n_unequiped;
    }
    return *this;
}

const std::string& Character::getName (void) const
{
    return (_name); 
}

void Character::equip(AMateria* m)
{
    if (m == NULL)
    {
        return ;
    }
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i] == NULL)
        {
            _inventory[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 || _inventory[idx] == NULL)
        return;
    if (_n_unequiped >= 100)
        return ;
    AMateria *tmp = _inventory[idx];
    _unequiped[_n_unequiped] = tmp;
    _inventory[idx] = NULL;
    _n_unequiped += 1;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4)
            return;

    if (this->_inventory[idx] != NULL)
    {
        this->_inventory[idx]->use(target);
    }
}