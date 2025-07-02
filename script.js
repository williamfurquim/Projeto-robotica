function trocarTexto(){
    const vp = document.getElementById("vp");
    const vn = document.getElementById("vn");
    const v34 = document.getElementById("34");
    const v32 = document.getElementById("32");
    const v33 = document.getElementById("33");
    const v25 = document.getElementById("25");
    const btns = document.getElementById("btn-sen");

    if (vp.textContent == "ENTRADA_VP" && vn.textContent == "ENTRADA_VN" && v34.textContent == "ENTRADA_D34" && v32.textContent == "ENTRADA_D32" && v33.textContent == "ENTRADA_D33" && v25.textContent == "ENTRADA_D25" && btns.textContent == "SENSORES"){
        vp.textContent = "BARREIRA";
        vn.textContent = "MAGAZINE RECUADO"
        v34.textContent = "MAGAZINE AVANÇADO"
        v32.textContent = "ROTATOR AVANÇADO"
        v33.textContent = "PRESSOSTATO"
        v25.textContent = "ROTATIVO RECUADO"
        btns.textContent = "ENTRADAS"
    } else {
        vp.textContent = "ENTRADA_VP";
        vn.textContent = "ENTRADA_VN";
        v34.textContent = "ENTRADA_D34";
        v32.textContent = "ENTRADA_D32";
        v33.textContent = "ENTRADA_D33";
        v25.textContent = "ENTRADA_D25"
        btns.textContent = "SENSORES"
    }
    
}

function trocarTexto2(){
    const s18 = document.getElementById("18");
    const s19 = document.getElementById("19");
    const s21 = document.getElementById("21");
    const s22 = document.getElementById("22");
    const s23 = document.getElementById("23");

    if (s18.textContent == "SAIDA_D18" && s19.textContent == "SAIDA_D19" && s21.textContent == "SAIDA_D21" && s22.textContent == "SAIDA_D22" && s23.textContent == "SAIDA_D23"){
        s18.textContent = "SOLTA PEÇA";
        s19.textContent = "VÁCUO";
        s21.textContent = "ATUADOR MAGAZINE";
        s22.textContent = "RECUADO";
        s23.textContent = "AVANÇO DO ATUADOR ROTATIVO";
    } else {
        s18.textContent = "SAIDA_D18";
        s19.textContent = "SAIDA_D19";
        s21.textContent = "SAIDA_D21";
        s22.textContent = "SAIDA_D22";
        s23.textContent = "SAIDA_D23";
    }
}