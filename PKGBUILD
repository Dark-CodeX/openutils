pkgname="openutils-date_time"
pkgver="1.1.0"
pkgrel="1"
pkgdesc="Date and time classes for C++."
arch=("x86_64" "i686")
conflicts=('openutils-date_time')
depends=(gcc)
license=("BSD 3-Clause License")
source=(
	"https://raw.githubusercontent.com/Dark-CodeX/date-time/main/date-time/date.hh"
	"https://raw.githubusercontent.com/Dark-CodeX/date-time/main/date-time/time.hh")

sha512sums=(
	"80e982f8d5a2bbd765983674d701e30e3050520820000fb01a42be02fd1875fc81e606f02e237815c0bd83252c666d52f23ccf942c0ee0ac0f1f525bb0368173"
	"073fd6bb6a7549afe5c5e27511950a32b4fd734f65365ce742135d80b008156ad2883d83e951bbc1f4bbb43891adf8277f94a4c8405672e1a772afcd1b68c5f1")

package() {
	echo "Date and time classes for C++."
	mkdir -p "${pkgdir}/usr/include/openutils/date-time"
	cp "${srcdir}/date.hh" "${pkgdir}/usr/include/openutils/date-time/date.hh"
	cp "${srcdir}/time.hh" "${pkgdir}/usr/include/openutils/date-time/time.hh"
	echo "Done!"
}
