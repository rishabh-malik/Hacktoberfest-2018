    Slider.prototype.processBtn = function (btn) {
        if (this.isAuto) {
            this.isAuto = false;
            clearInterval(this.auto);
        }
        if (btn.hasClass('next'))
            this.updateNext();
            if(btn.hasClass('previous'))
            this.updatePrevious();
    };
