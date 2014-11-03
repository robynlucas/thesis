.PHONY: clean

EXTRASTYS = abhepexpt.sty abhep.sty  abmath.sty lineno.sty SIunits.sty varwidth.sty

mythesis.pdf: mythesis.tex mythesis.cls chap_theory.tex chap_detector.tex chap_l1jets.tex chap_compSUSY.tex chap_parkedData.tex frontmatter.tex appendices.tex
	@rm -f $(EXTRASTYS)
	unzip extrastyles.zip
	@rm -f mythesis.{aux,toc,lof,lot}
	(pdflatex mythesis && bibtex mythesis && pdflatex mythesis && pdflatex mythesis) || rm -f $(EXTRASTYS) mythesis.pdf
	@rm -f mythesis.{aux,toc,lof,lot}
	@rm -f $(EXTRASTYS)

clean:
	@rm -f $(EXTRASTYS)
	@rm -f mythesis.pdf mythesis.log mythesis.aux
	@rm -f *.bbl *.blg *.lof *.cut
	@rm -f *.lot *.out *.toc
