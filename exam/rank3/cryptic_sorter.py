def cryptic_sorter(tlist: list) -> list:
    def counter(el):
        cont = 0
        for i in el:
            if i.lower() in "aeiou":
                cont += 1
        return (cont, len(el), el.lower())
    return (sorted(tlist, key=counter))
