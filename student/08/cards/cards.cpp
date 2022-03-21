#include "cards.hh"

// TODO: Implement the methods here

Cards::Cards(): top_(nullptr)
{

}

Card_data *Cards::get_topmost()
{
    return top_;
}

void Cards::add(int id)
{
       Card_data *uusi_kortti = new Card_data;
       uusi_kortti->data = id;
       uusi_kortti->next = top_;
       top_ = uusi_kortti;

}

void Cards::print_from_top_to_bottom(std::ostream &s)
{

    Card_data* item_to_be_printed = top_;
    int running_number = 1;

    while ( item_to_be_printed != nullptr ) {
       s << running_number << ": " << item_to_be_printed->data << std::endl;
       ++running_number;
       item_to_be_printed = item_to_be_printed->next;
    }
}

bool Cards::remove(int &id)
{
    if(top_ == nullptr)
    {
        return false;
    }

    Card_data* poistettava_kortti = top_;
    id = poistettava_kortti->data;
    top_ = top_->next;
    delete poistettava_kortti;
    return true;
}

bool Cards::bottom_to_top()
{
    if(top_ == nullptr)
    {
        return false;
    }
    Card_data *pohjimmainen = top_,
                *toiseksi_viimeinen = top_;
    while(pohjimmainen->next != nullptr)
    {
        toiseksi_viimeinen = pohjimmainen;
        pohjimmainen = pohjimmainen->next;
    }
    toiseksi_viimeinen->next = nullptr;
    pohjimmainen->next = top_;
    top_ = pohjimmainen;
    return true;

}

bool Cards::top_to_bottom()
{
    if(top_ == nullptr)
    {
        return false;
    }
    Card_data *siirretty_kortti = top_,
               *pohjimmainen = top_;
    top_ = top_-> next;
    while(pohjimmainen->next != nullptr)
    {;
        pohjimmainen = pohjimmainen->next;
    }

    pohjimmainen->next = siirretty_kortti;
    siirretty_kortti->next = nullptr;
    return true;
}

void Cards::print_from_bottom_to_top(std::ostream &s)
{

}


Cards::~Cards()
{
       while ( top_ != nullptr ) {
          Card_data* poistettava_kortti = top_;
          top_ = top_->next;

          delete poistettava_kortti;
       }
    }


int Cards::recursive_print(Card_data *top, std::ostream &s)
{

}
