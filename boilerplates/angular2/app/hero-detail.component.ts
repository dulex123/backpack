import { Component, OnInit, Input, EventEmitter, Output } from '@angular/core';
import { ActivatedRoute, Params } from '@angular/router';

import { Hero } from './hero';
import { HeroService } from './hero.service';

@Component({
    selector: 'my-hero-detail',
    templateUrl: 'app/views/hero-detail.component.html',
    styleUrls: ['app/styles/hero-detail.component.css']
})
export class HeroDetailComponent implements OnInit {
    @Input()
    hero: Hero;

    @Output()
    close = new EventEmitter();
    error: any;
    navigated = false;

    constructor(
        private heroService: HeroService,
        private route: ActivatedRoute) {
    }

    ngOnInit() {
        this.route.params.forEach((params: Params) => {
            if (params['id'] !== undefined) {
                let id = +params['id'];
                this.navigated = true;
                this.heroService.getHero(id)
                .then(hero => this.hero = hero);
            } else {
                this.navigated = false;
                this.hero = new Hero();
            }
        });
    }
    save() {
        this.heroService
        .save(this.hero)
        .then(hero => {
            this.hero = hero; // saved hero, w/ id if new
            this.goBack(hero);
        }).catch(error => this.error = error); // TODO: Display error message
    }


    goBack(savedHero: Hero = null) {
        this.close.emit(savedHero);
        if (this.navigated) { window.history.back(); }
    }
}
