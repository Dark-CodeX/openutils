pkgname="openutils-date_time"
pkgver="1.0.0"
pkgrel="1"
pkgdesc="Date and time classes for C++."
arch=("x86_64" "i686")
conflicts=('openutils-date_time')
depends=(gcc)
license=("MIT")
source=(
	"https://raw.githubusercontent.com/Dark-CodeX/date-time/main/date-time/date.hh"
	"https://raw.githubusercontent.com/Dark-CodeX/date-time/main/date-time/time.hh")

sha512sums=(
	"e5b86decbe927de69de25948b3af268ee89a86326b9ed2c8ee0cb5dae514c81a35431088d23b5871d4dab5c7652ea7cc1fa9e5ef2c3f015917ce5aecf36529e4"
	"2b7365765b2fbdbb7ff1f80c8157fd80c43c770fc46d41eb7d2a06d808568b3e4564ad8ed4070bef856fa48543d0ee5542c455ae5a24f3a319c810bdd51ca855")

package() {
	echo "Date and time classes for C++."
	mkdir -p "${pkgdir}/usr/include/openutils/date-time"
	cp "${srcdir}/date.hh" "${pkgdir}/usr/include/openutils/date-time/date.hh"
	cp "${srcdir}/time.hh" "${pkgdir}/usr/include/openutils/date-time/time.hh"
	echo "Done!"
}
